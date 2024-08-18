#include<gtk/gtk.h>
#include"graph.h"
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button[26];
}calc;
GtkWidget *box;
GtkWidget *box2;

char input_buffer[100] = {0};
char output_buffer[100] = {0};

bool clear_buffer = false;

void calculate(GtkButton *button){
	const gchar* text = gtk_button_get_label(button);
	if(strcmp("=",text)==0){
		gtk_entry_set_text(GTK_ENTRY(box), "");
		
		sprintf(output_buffer, "%.3lf",result_output(output_buffer));
		gtk_entry_set_text(GTK_ENTRY(box), output_buffer);
	}
	else{
		if(clear_buffer){
			memset(input_buffer,0,strlen(input_buffer));
			clear_buffer = false;
		}else{
			strncat(input_buffer,text, strlen(text));
		}
			strncat(output_buffer,text, strlen(text));
			gtk_entry_set_text(GTK_ENTRY(box), output_buffer);
	}
	if(strcmp("C",text)==0){
		gtk_entry_set_text(GTK_ENTRY(box), "");
		memset(input_buffer,0,strlen(input_buffer));
		memset(output_buffer,0,strlen(output_buffer));
	}
}
void activate(GtkApplication *app){
	calc widget;

	widget.window = gtk_application_window_new(app);
	gtk_window_set_position(GTK_WINDOW(widget.window),GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(widget.window),"Las Creations Calculator");
	gtk_window_set_default_size(GTK_WINDOW(widget.window),300, 200);
	gtk_container_set_border_width(GTK_CONTAINER(widget.window),10);

	widget.grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(widget.window),widget.grid);

	box = gtk_entry_new();
	gtk_editable_set_editable(GTK_EDITABLE(box), FALSE);

	widget.button[0] = gtk_button_new_with_label("0");
	widget.button[1] = gtk_button_new_with_label("1");
	widget.button[2] = gtk_button_new_with_label("2");
	widget.button[3] = gtk_button_new_with_label("3");
	widget.button[4] = gtk_button_new_with_label("4");
	widget.button[5] = gtk_button_new_with_label("5");
	widget.button[6] = gtk_button_new_with_label("6");
	widget.button[7] = gtk_button_new_with_label("7");
	widget.button[8] = gtk_button_new_with_label("8");
	widget.button[9] = gtk_button_new_with_label("9");
	widget.button[10] = gtk_button_new_with_label(".");
	widget.button[11] = gtk_button_new_with_label("+");
	widget.button[12] = gtk_button_new_with_label("-");
	widget.button[13] = gtk_button_new_with_label("*");
	widget.button[14] = gtk_button_new_with_label("/");
	widget.button[15] = gtk_button_new_with_label("C");
	widget.button[16] = gtk_button_new_with_label("=");
	widget.button[17] = gtk_button_new_with_label("(");
	widget.button[18] = gtk_button_new_with_label(")");
	widget.button[19] = gtk_button_new_with_label("sin");
	widget.button[20] = gtk_button_new_with_label("cos");
	widget.button[21] = gtk_button_new_with_label("ln");
	widget.button[22] = gtk_button_new_with_label("x");
	widget.button[23] = gtk_button_new_with_label("tan");
	widget.button[24] = gtk_button_new_with_label("ctg");
	widget.button[25] = gtk_button_new_with_label("!");
	widget.button[26] = gtk_button_new_with_label("√");

	gtk_grid_attach(GTK_GRID(widget.grid),box,0,0,6,1);
	//gtk_grid_attach(GTK_GRID(widget.grid),box2,6,1,6,6);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[15],0,1,3,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[14],3,1,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[17],4,1,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[18],5,1,1,1);
	
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[7],0,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[8],1,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[9],2,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[13],3,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[19],4,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[23],5,2,1,1);

	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[4],0,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[5],1,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[6],2,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[12],3,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[20],4,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[24],5,3,1,1);

	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[1],0,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[2],1,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[3],2,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[11],3,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[21],4,4,1,1);

	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[0],0,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[10],1,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[25],2,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[26],3,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[22],4,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[16],5,4,1,2);
	
	//gtk_container_add(GTK_CONTAINER(app), widget.grid);
	for (int i = 0; i < 27; i++){
		g_signal_connect(widget.button[i],"clicked",G_CALLBACK(calculate), NULL);
	}
	gtk_widget_show_all(widget.window);
}

int main(int argc, char **argv){
	GtkApplication *app;
	gtk_init(&argc, &argv);
	int status;
	app = gtk_application_new("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);

	g_signal_connect(app,"activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}