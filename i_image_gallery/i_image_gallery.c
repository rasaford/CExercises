// For a proper basename() function
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <unistd.h>
#include "gui.h"
#include <pthread.h>

//
// GUI globals
//

Ihandle* path_text = NULL;
Ihandle* gallery_grid_box = NULL;
Ihandle* gallery_scroll_box = NULL;


void* worker_thread_main(void* arg) {
    printf("worker_thread: started\n");
    printf("worker_thread: finished\n");
    return NULL;
}
//
// GUI callbacks for images in the gallery
//

/**
 * When a thumbnail gets the focus change it's background color to the highlight color.
 * This way the users knows he has selected that thumbnail.
 */
int thumb_getfocus_cb(Ihandle* self) {
	char* highlight_color = IupGetGlobal("TXTHLCOLOR");
	IupSetStrAttribute(self, "BGCOLOR", highlight_color);
	return IUP_DEFAULT;
}

/**
 * When a thumbnail loses the focus change it's background color back so the user knows
 * it's no longer selected.
 */
int thumb_killfocus_cb(Ihandle* self) {
	char* background_color = IupGetGlobal("DLGBGCOLOR");
	IupSetAttribute(self, "BGCOLOR", background_color);
	return IUP_DEFAULT;
}

/**
 * When the user double clicks on a thumbnail we open it with the "gnome-open" command.
 * The fork() function is used to create a new process and execlp() is used to execute gnome-open
 * in that new process. If for whatever reason execlp() should fail the child process exits immediatly.
 */
int thumb_button_cb(Ihandle* self, int button, int pressed, int x, int y, char* status) {
	if ( iup_isdouble(status) ) {
		char* img_path = IupGetAttribute(self, "path");
		printf("%s: Opening image...\n", basename(img_path));

		pid_t child_pid = fork();
		if (child_pid == 0) {
			execlp("gnome-open", "gnome-open", img_path, NULL);
			exit(0);
		}
	}
	return IUP_DEFAULT;
}


//
// GUI callbacks for the main window
//

/**
 * Adjust the number of columns in the gallery grid box when the dialog is resized.
 * We do this so the gallery always uses as many columns as will fit into the window.
 */
int dlg_resize_cb(Ihandle* self, int width, int height) {
	int available_width = IupGetInt(gallery_scroll_box, "CLIENTSIZE");
	int num_of_columns = (available_width - 10) / 110;
	IupSetInt(gallery_grid_box, "NUMDIV", num_of_columns);
	IupRefresh(gallery_grid_box);

	return IUP_DEFAULT;
}

/**
 * When the user presses the load button we list all files in the directory entered by the user.
 * For each file in there we load the image, resize it to thumbnail size and add it to the GUI.
 */
int load_gallery_cb(Ihandle* self) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, worker_thread_main, 0);
    pthread_detach(thread_id);

	char* path = IupGetAttribute(path_text, "VALUE");
	printf("Loading images from directory at %s\n", path);

	// Step 1: Get a list of all files in the directory
	glob_t files = { 0 };
	char* glob_pattern = NULL;
	asprintf(&glob_pattern, "%s/*", path);
		glob(glob_pattern, 0, NULL, &files);
	free(glob_pattern);

	for(int i = 0; i < files.gl_pathc; i++) {
		char* img_path = files.gl_pathv[i];

		// Step 2: Add thumbnail with placeholder to GUI
		printf("%s: Inserting thumbnail placeholder into GUI\n", basename(img_path));
		// Stuff in thumb_focus_box
			// Stuff in thumb_vbox
				Ihandle* thumb_img_label = IupLabel("");
					IupSetAttribute(thumb_img_label, "IMAGE", "image-loading");
					IupSetAttribute(thumb_img_label, "RASTERSIZE", "100x100");
					IupSetAttribute(thumb_img_label, "ALIGNMENT", "ACENTER:ACENTER");
				Ihandle* thumb_name_label = IupLabel("");
					IupSetStrAttribute(thumb_name_label, "TITLE", basename(img_path));
					IupSetAttribute(thumb_name_label, "ALIGNMENT", "ACENTER:");
					IupSetAttribute(thumb_name_label, "ELLIPSIS", "YES");
					IupSetAttribute(thumb_name_label, "RASTERSIZE", "100x");
			Ihandle* thumb_vbox = IupVbox(thumb_img_label, thumb_name_label, NULL);
				IupSetAttribute(thumb_vbox, "ALIGNMENT", "ACENTER");
				IupSetAttribute(thumb_vbox, "EXPAND", "NO");
		Ihandle* thumb_focus_box = IupBackgroundBox(thumb_vbox);
			IupSetAttribute(thumb_focus_box, "CANFOCUS", "YES");
			IupSetCallback(thumb_focus_box, "GETFOCUS_CB", thumb_getfocus_cb);
			IupSetCallback(thumb_focus_box, "KILLFOCUS_CB", thumb_killfocus_cb);
			IupSetCallback(thumb_focus_box, "BUTTON_CB", (Icallback)thumb_button_cb);
			// Copy the image path into a new attribute so we know the path for each thumbnail later on
			IupSetStrAttribute(thumb_focus_box, "path", img_path);

		// Insert new thumbnail GUI elements into the gallery grid box
		IupAppend(gallery_grid_box, thumb_focus_box);
		IupMap(thumb_focus_box);
		IupRefresh(gallery_grid_box);

		// Step 3: Try to load the file with the STB image library. If it's not an image NULL is returned.
		printf("%s: Loading image...\n", basename(img_path));
		int img_w = 0, img_h = 0;
		unsigned char* img_ptr = stbi_load(img_path, &img_w, &img_h, NULL, 4);

		// Step 4: Resize the image to thumbnail size. That is if we successfully loaded the image in the
		// first place. If not we'll just leave thumb_ptr with a value of NULL.
		unsigned char* thumb_ptr = NULL;
		int thumb_w = 0, thumb_h = 0;
		if (img_ptr) {
			// Figure out the width and height of our thumbnail
			float img_aspect_ratio = (float)img_w / img_h;
			if (img_aspect_ratio > 1) {
				// Image is wider than high ("landscape" image). Width is the defining dimension for our thumbnail.
				thumb_w = 100;
				thumb_h = 100 / img_aspect_ratio;
			} else {
				// Image is higher than wide ("portrait" image). Hight is the defining dimension for our thumbnail.
				thumb_w = 100 * img_aspect_ratio;
				thumb_h = 100;
			}

			// Allocate memory for thumbnail and resize the image into the thumbnail using the STB image resize library.
			printf("%s: Resizing to thumbnail\n", basename(img_path));
			thumb_ptr = malloc(thumb_w * thumb_h * 4);
			stbir_resize_uint8(img_ptr, img_w, img_h, 0, thumb_ptr, thumb_w, thumb_h, 0, 4);

			// Free memory of the loaded image. We have our thumbnail and no longer need the image in full resolution.
			free(img_ptr);
		}

		// Step 5: Update placeholder with real thumbnail or "unknown" placeholder
		printf("%s: Updating placeholder...\n", basename(img_path));
		if (thumb_ptr) {
			// Image loaded and thumbnail available
			Ihandle* thumb_handle = IupImageRGBA(thumb_w, thumb_h, thumb_ptr);
				IupSetAttribute(thumb_handle, "AUTOSCALE", "NO");
			IupSetAttributeHandle(thumb_img_label, "IMAGE", thumb_handle);

			// Free memory of our thumbnail. The GUI library copied the thumbnail data into the IupImageRGBA
			// object. So we can free our thumbnail memory.
			free(thumb_ptr);
		} else {
			IupSetAttribute(thumb_img_label, "IMAGE", "unknown");
		}
	}
	globfree(&files);

	return IUP_DEFAULT;
}


int main() {
	IupOpen(NULL, NULL);
	IupSetGlobal("IMAGESTOCKSIZE", "48");

	// Row of input controls
		path_text = IupText(NULL);
			IupSetAttribute(path_text, "VALUE", "");
			IupSetAttribute(path_text, "CUEBANNER", "Enter path to image directory");
			IupSetAttribute(path_text, "EXPAND", "HORIZONTAL");
		Ihandle* load_button = IupButton("Load", NULL);
			IupSetCallback(load_button, "ACTION", load_gallery_cb);
	Ihandle* input_row = IupHbox(path_text, load_button, NULL);

	// Main area for gallery
		gallery_grid_box = IupGridBox(NULL);
			IupSetAttribute(gallery_grid_box, "HOMOGENEOUSLIN", "YES");
			IupSetAttribute(gallery_grid_box, "NGAPLIN", "10");
			IupSetAttribute(gallery_grid_box, "NGAPCOL", "10");
			IupSetAttribute(gallery_grid_box, "NMARGIN", "10x10");
	gallery_scroll_box = IupScrollBox(gallery_grid_box);

	Ihandle* dialog = IupDialog(IupVbox(input_row, gallery_scroll_box, NULL));
		IupSetAttribute(dialog, "TITLE", "Image Gallery");
		IupSetAttribute(dialog, "MINSIZE", "500x400");
		IupSetCallback(dialog, "RESIZE_CB", (Icallback)dlg_resize_cb);

	IupShow(dialog);
	IupMainLoop();

	IupClose();
	return 0;
}
