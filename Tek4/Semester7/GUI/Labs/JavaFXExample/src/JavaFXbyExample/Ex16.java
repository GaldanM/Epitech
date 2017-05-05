package JavaFXbyExample;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Ex16 extends Application {
    private VBox vb_mainlayout;
    private Label lbl_display;
    private TextField tf_adding;
    private ListView<String> lv_strings;
    private ObservableList<String> ol_strings;

    public void init() {
        vb_mainlayout = new VBox();
        lbl_display = new Label("no item selected");
        ol_strings = FXCollections.observableArrayList("one", "two", "three", "four");
        lv_strings = new ListView<String>(ol_strings);
        tf_adding = new TextField();

        vb_mainlayout.getChildren().addAll(lbl_display, lv_strings, tf_adding);

        tf_adding.setOnAction(event -> ol_strings.add(tf_adding.getText()));

        lv_strings.getSelectionModel().selectedItemProperty().addListener(
                (observable, old_value, new_value) ->
                        lbl_display.setText("Item selected: " + new_value)
        );
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
