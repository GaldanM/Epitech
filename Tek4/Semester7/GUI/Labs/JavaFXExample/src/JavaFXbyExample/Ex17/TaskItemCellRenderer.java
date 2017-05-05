package JavaFXbyExample.Ex17;

import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.ListCell;
import javafx.scene.layout.HBox;

public class TaskItemCellRenderer extends ListCell<TaskItem> {

    private HBox hb_mainlayout;
    private CheckBox cb_done;
    private Label lbl_task_name;
    private Ex17 ref;

    public TaskItemCellRenderer(Ex17 ref) {
        super();
        this.ref = ref;

        hb_mainlayout = new HBox();
        cb_done = new CheckBox();
        lbl_task_name = new Label();
        hb_mainlayout.getChildren().addAll(cb_done, lbl_task_name);

        cb_done.setOnAction(event -> {
            itemProperty().get().complete = cb_done.isSelected();
            ref.taskItemChanged(itemProperty().get());
        });
    }

    @Override
    public void updateItem(TaskItem item, boolean empty) {
        super.updateItem(item, empty);
        if(!empty && item != null) {
            cb_done.setSelected(item.complete);
            lbl_task_name.setText(item.name);
            setGraphic(hb_mainlayout);
        } else {
            setGraphic(null);
        }
    }
}
