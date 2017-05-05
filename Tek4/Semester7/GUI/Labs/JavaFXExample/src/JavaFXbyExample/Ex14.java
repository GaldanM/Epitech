package JavaFXbyExample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Ex14 extends Application {
    private VBox vb_mainlayout;
    private Label lbl_display;
    private MenuBar mb_menubar;
    private Menu menu_file, menu_help;
    private MenuItem mi_hello, mi_quit;
    private RadioMenuItem rmi_rb1, rmi_rb2;
    private CheckMenuItem cbmi_cb1, cbmi_cb2;
    private ToggleGroup tg_rmi;

    public void init() {
        vb_mainlayout = new VBox();
        lbl_display = new Label("No menu item selected");
        mb_menubar = new MenuBar();
        menu_file = new Menu("File");
        menu_help = new Menu("Help");
        mb_menubar.getMenus().addAll(menu_file, menu_help);
        vb_mainlayout.getChildren().addAll(mb_menubar, lbl_display);

        mi_hello = new MenuItem("Hello");
        mi_quit = new MenuItem("Quit");
        cbmi_cb1 = new CheckMenuItem("check box 1");
        cbmi_cb2 = new CheckMenuItem("check box 2");
        menu_file.getItems().addAll(mi_hello, mi_quit, cbmi_cb1, cbmi_cb2);

        tg_rmi = new ToggleGroup();
        rmi_rb1 = new RadioMenuItem("Radio button 1");
        rmi_rb2 = new RadioMenuItem("Radio button 2");
        rmi_rb1.setToggleGroup(tg_rmi);
        rmi_rb2.setToggleGroup(tg_rmi);
        menu_help.getItems().addAll(rmi_rb1, rmi_rb2);

        mi_hello.setOnAction(event -> lbl_display.setText("Selected hello menu item"));
        cbmi_cb1.setOnAction(event -> lbl_display.setText("Selected check box menu item are : " + (cbmi_cb1.isSelected() ? "1" : "") + (cbmi_cb2.isSelected() ? ", 2" : "")));
        cbmi_cb2.setOnAction(event -> lbl_display.setText("Selected check box menu item are : " + (cbmi_cb1.isSelected() ? "1" : "") + (cbmi_cb2.isSelected() ? ", 2" : "")));
        rmi_rb1.setOnAction(event -> lbl_display.setText("Selected radio menu item 1"));
        rmi_rb2.setOnAction(event -> lbl_display.setText("Selected radio menu item 2"));
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Melchior FTW");
        primaryStage.setScene(new Scene(vb_mainlayout, 400, 300));
        primaryStage.show();
    }

    @Override
    public void stop() {
    }

    public static void main(String[] args) {
        launch(args);
    }
}
