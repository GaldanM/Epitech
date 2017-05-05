package JavaFXbyExample;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Ex13 extends Application {
    private Label lbl_display;
    private Slider sli_slider;
    private VBox vb_mainlayout;

    public void init() {
        lbl_display = new Label("slider value set to: 5.0");
        sli_slider = new Slider(0, 10, 5);
        vb_mainlayout = new VBox();
        vb_mainlayout.getChildren().addAll(lbl_display, sli_slider);

        sli_slider.setShowTickMarks(true);
        sli_slider.setShowTickLabels(true);
        sli_slider.setMajorTickUnit(1);
        sli_slider.setBlockIncrement(0.5);

        sli_slider.valueProperty().addListener((observable, oldValue, newValue) -> lbl_display.setText("slider value set to: " + newValue));
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
