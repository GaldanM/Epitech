import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Paint;
import javafx.stage.Stage;

public class Abalone extends Application {
    private VBox main_vb;

    @Override
    public void init() {
        main_vb = new VBox();

        Board board = new Board();

        MenuBar mb = new MenuBar();
        Menu resetGame = new Menu();
        Label reset = new Label("Reset");
        reset.setOnMouseClicked(event -> {
            board.reset();
        });
        resetGame.setGraphic(reset);
        mb.getMenus().add(resetGame);

        main_vb.getChildren().addAll(mb, board);
        main_vb.setBackground(new Background(new BackgroundFill(Paint.valueOf("#424242"), CornerRadii.EMPTY, Insets.EMPTY)));
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Abalone");
        primaryStage.setScene(new Scene(main_vb, 700, 700));
        primaryStage.setResizable(false);
        primaryStage.show();
    }

    @Override
    public void stop() {
    }

    public static void main(String[] args) {
        launch(args);
    }
}