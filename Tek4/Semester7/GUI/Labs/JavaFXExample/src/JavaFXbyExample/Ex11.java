package JavaFXbyExample;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class Ex11 extends Application {
    private VBox vb_mainlayout;
    private TextArea ta_textarea, ta_response;

    public void init() {
        vb_mainlayout = new VBox();
        ta_textarea = new TextArea();
        ta_response = new TextArea();

        vb_mainlayout.getChildren().addAll(ta_textarea, ta_response);
        ta_response.setEditable(false);

        ta_textarea.textProperty().addListener((observable, oldValue, newValue) -> ta_response.setText(newValue));
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
