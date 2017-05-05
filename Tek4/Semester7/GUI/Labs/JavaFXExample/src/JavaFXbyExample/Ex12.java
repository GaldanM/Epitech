package JavaFXbyExample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Ex12 extends Application {
    private Label lbl_display;
    private VBox vb_mainlayout;
    private ComboBox<String> cmb_combobox;

    public void init() {
        vb_mainlayout = new VBox();
        lbl_display = new Label("ComboBox: No current selection");
        cmb_combobox = new ComboBox<String>();
        cmb_combobox.getItems().addAll("This is choice 1", "This is choice 2", "This is choice 3");

        vb_mainlayout.getChildren().addAll(lbl_display, cmb_combobox);
        cmb_combobox.setOnAction(event -> lbl_display.setText("ComboBox: " + cmb_combobox.getValue()));
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
