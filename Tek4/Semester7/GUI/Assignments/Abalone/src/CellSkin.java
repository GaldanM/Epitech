import javafx.scene.control.Skin;
import javafx.scene.control.SkinBase;

class CellSkin extends SkinBase<Cell> implements Skin<Cell> {
    CellSkin(Cell control) {
        super(control);
    }
}
