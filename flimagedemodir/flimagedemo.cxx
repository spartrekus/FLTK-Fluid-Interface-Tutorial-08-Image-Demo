// Image demo

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.H>

// Global pointers for the GUI objects
Fl_Window *mywindow;
Fl_Button *chessgamebutton;
Fl_Button *ruinpicbutton;
Fl_Box *mypicturebox;
Fl_JPEG_Image *startimg;
Fl_JPEG_Image *chessgameimg;
Fl_JPEG_Image *ruinpicimg;

// Callback function
void mybutton_cb(Fl_Widget * w, long int data)
{
	if (data == 8) {
		mypicturebox->image(chessgameimg);
		mypicturebox->redraw();
		//chessgamebutton->redraw();
	}
	if (data == 4) {
		mypicturebox->image(ruinpicimg);
		mypicturebox->redraw();
	}
}
int main()
{

	// The main window
	mywindow = new Fl_Window(300, 220, "FLTK");

	// Two buttons, sharing one callback
	chessgamebutton = new Fl_Button(50, 50, 50, 30, "Chess");
	ruinpicbutton = new Fl_Button(200, 50, 50, 30, "Ruin");
	chessgamebutton->callback(mybutton_cb, 8);
	ruinpicbutton->callback(mybutton_cb, 4);

	// Load some images to use later
	startimg = new Fl_JPEG_Image("greek.jpg");
	chessgameimg = new Fl_JPEG_Image("chessgame.jpg");
	ruinpicimg = new Fl_JPEG_Image("ruinpic.jpg");

	// A box for the image
	mypicturebox = new Fl_Box(100, 100, 100, 100);

	// Give it some initial contents
	mypicturebox->image(startimg);

	// Make the window visible and start processing events
	mywindow->end();
	mywindow->show();
	return Fl::run();
}






