package JavaFXbyExample;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Ex15 extends Application {
    private VBox vb_mainlayout;
    private ProgressBar pb_bar;
    private Slider sli_slider;

    public void init() {
        vb_mainlayout = new VBox();
        pb_bar = new ProgressBar(0.5);
        sli_slider = new Slider(0, 100, 50);
        vb_mainlayout.getChildren().addAll(pb_bar, sli_slider);

        sli_slider.setShowTickMarks(true);
        sli_slider.setShowTickLabels(true);
        sli_slider.setMajorTickUnit(10);
        pb_bar.setMaxWidth(Double.MAX_VALUE);

        sli_slider.valueProperty().addListener((observable, oldValue, newValue) -> pb_bar.setProgress((double) newValue / 100));
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
