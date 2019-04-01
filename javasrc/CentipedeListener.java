import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.util.HashMap;

/**
 * 
 * KeyListener which handles keyboard input for the centipede game. Keeps track of which keys
 * currently being pressed
 *
 * @author localmgr.
 *         Created May 4, 2016.
 */
public class CentipedeListener implements KeyListener {
	
	public HashMap<Integer, Boolean> keyPressedMap;
	public CentipedeComponent component;
	
	@SuppressWarnings("boxing")
	public CentipedeListener(CentipedeComponent component) {
		this.component = component;
		this.keyPressedMap = new HashMap<>();
		this.keyPressedMap.put(37, false);
		this.keyPressedMap.put(38, false);
		this.keyPressedMap.put(39, false);
		this.keyPressedMap.put(40, false);
		this.keyPressedMap.put(85, false);
		this.keyPressedMap.put(68, false);
		this.keyPressedMap.put(32, false);
		this.keyPressedMap.put(com.sun.glass.events.KeyEvent.VK_PERIOD, false);
		this.keyPressedMap.put(com.sun.glass.events.KeyEvent.VK_COMMA, false);
	}
	
	public HashMap<Integer, Boolean> getHashMap(){
		return this.keyPressedMap;
	}

	@Override
	public void keyTyped(KeyEvent e) {
		// Typed stuff

	}

	@SuppressWarnings("boxing")
	@Override
	public void keyPressed(KeyEvent e) {
		int keyCode = e.getKeyCode();
		
		this.keyPressedMap.put(keyCode, true);
	}

	@Override
	public void keyReleased(KeyEvent e) {
		int keyCode = e.getKeyCode();
		
		this.keyPressedMap.put(keyCode, false);
		
		if (keyCode == KeyEvent.VK_U) {
			int nextLevel = 0;
			if(this.component.getLevelNum()==2){
				nextLevel = 0;
			}
			else{
				nextLevel = this.component.getLevelNum() + 1;
			}
			try{
				this.component.loadLevel(nextLevel);
			}
			catch(IOException ex){
				System.out.println("ERROR LOADING LEVEL");
			}
		}
		if (keyCode == KeyEvent.VK_D) {
			int nextLevel = 0;
			if(this.component.getLevelNum()==0){
				nextLevel = 2;
			}
			else{
				nextLevel = this.component.getLevelNum() - 1;
			}
			try{
				this.component.loadLevel(nextLevel);
			}
			catch(IOException ex){
				System.out.println("ERROR LOADING LEVEL");
			}
		}
		if (keyCode == KeyEvent.VK_P) {
			this.component.setIsPaused(!this.component.IsPaused);
		}
		if(keyCode == KeyEvent.VK_PERIOD){
			if(this.component.getCharacter().getGunID() != 3){
				this.component.getCharacter().changeGun(this.component.getCharacter().getGunID()+1);
			}
			else{
				this.component.getCharacter().changeGun(1);
			}
		}
		if(keyCode == KeyEvent.VK_COMMA){
			if(this.component.getCharacter().getGunID() != 1){
				this.component.getCharacter().changeGun(this.component.getCharacter().getGunID()-1);
			}
			else{
				this.component.getCharacter().changeGun(3);
			}
		}
	}
}
