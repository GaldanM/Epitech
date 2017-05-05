package UltimateTicTacToe;

import javafx.scene.control.Skin;
import javafx.scene.control.SkinBase;

class CustomControlSkin extends SkinBase<CustomControl> implements Skin<CustomControl> {
    CustomControlSkin(CustomControl control) {
        super(control);
    }
}
