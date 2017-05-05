package JavaFXbyExample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextArea;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Ex18 extends Application {
    private VBox vb_mainlayout;
    private TabPane tp_tabs;
    private Tab tab_one, tab_two, tab_three;
    private VBox vb_one, vb_two, vb_three;
    private TextArea ta_one, ta_two, ta_three;

    public void init() {
        vb_mainlayout = new VBox();
        tp_tabs = new TabPane();
        vb_mainlayout.getChildren().add(tp_tabs);

        vb_one = new VBox();
        ta_one = new TextArea();
        vb_one.getChildren().add(ta_one);
        tab_one = new Tab("First Area");
        tab_one.setContent(vb_one);
        tp_tabs.getTabs().add(tab_one);

        vb_two = new VBox();
        ta_two = new TextArea();
        vb_two.getChildren().add(ta_two);
        tab_two = new Tab("Second Area");
        tab_two.setContent(vb_two);
        tp_tabs.getTabs().add(tab_two);

        vb_three = new VBox();
        ta_three = new TextArea();
        vb_three.getChildren().add(ta_three);
        tab_three = new Tab("Third Area");
        tab_three.setContent(vb_three);
        tp_tabs.getTabs().add(tab_three);
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
