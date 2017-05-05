package JavaFXbyExample;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.awt.event.ActionEvent;
import java.time.LocalDate;

public class Ex19 extends Application {
    private VBox vb_mainlayout;
    private DatePicker dp_date;
    private Label lbl_display;

    public void init() {
        vb_mainlayout = new VBox();
        dp_date = new DatePicker(LocalDate.now());
        lbl_display = new Label();
        vb_mainlayout.getChildren().addAll(lbl_display, dp_date);

        dp_date.setOnAction(event -> {
            lbl_display.setText("New date chosen is: " + dp_date.getValue());
        });
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
