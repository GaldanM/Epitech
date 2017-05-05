package JavaFXbyExample.Ex17;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.util.ArrayList;

public class Ex17 extends Application {
    private VBox vb_mainlayout;
    private ArrayList<TaskItem> al_taskitems;
    private ObservableList<TaskItem> ol_items;
    private ListView<TaskItem> lv_items;
    private Label lbl_display;
    private TextField tf_adding;

    public void init() {
        al_taskitems = new ArrayList<TaskItem>();
        al_taskitems.add(new TaskItem(false, "task 1"));
        al_taskitems.add(new TaskItem(true, "task 2"));
        al_taskitems.add(new TaskItem(false, "task 3"));
        al_taskitems.add(new TaskItem(true, "task 4"));

        vb_mainlayout = new VBox();
        ol_items = FXCollections.observableArrayList(al_taskitems);
        lv_items = new ListView<TaskItem>(ol_items);
        lbl_display = new Label("no item selected");
        tf_adding = new TextField();
        vb_mainlayout.getChildren().addAll(lbl_display, lv_items, tf_adding);

        lv_items.setCellFactory(list -> {
            TaskItemCellRenderer r = new TaskItemCellRenderer(Ex17.this);
            r.setEditable(true);
            return r;
        });

        lv_items.getSelectionModel().selectedItemProperty().addListener(
                (observable, old_value, new_value) ->
                        lbl_display.setText("Item selected: " + new_value.name)
        );

        tf_adding.setOnAction(event -> {
            TaskItem temp = new TaskItem(false, tf_adding.getText());
            ol_items.add(temp);
            tf_adding.clear();
        });
    }

    public void taskItemChanged(TaskItem item) {
        lbl_display.setText("state changed on item: " + item.name);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Custom ListView item example");
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
