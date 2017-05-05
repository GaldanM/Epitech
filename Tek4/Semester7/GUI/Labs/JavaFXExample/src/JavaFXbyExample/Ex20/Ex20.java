package JavaFXbyExample.Ex20;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Ex20 extends Application {
    private StackPane sp_main;
    private CustomControl cc_main;

    @Override
    public void init() {
        sp_main = new StackPane();
        cc_main = new CustomControl();
        sp_main.getChildren().add(cc_main);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Morpion FTW");
        primaryStage.setScene(new Scene(sp_main, 800, 600));
        primaryStage.show();
    }

    @Override
    public void stop() {
    }

    public static void main(String[] args) {
        launch(args);
    }
}
