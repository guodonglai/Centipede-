import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.HashMap;


public class GunPickup extends Instance {
	
	private final int PISTOL_NUMBER = 1;
	private final int SHOTGUN_NUMBER = 2;
	private final int BOOMERANG_NUMBER = 3;
	
	private HashMap<Integer, Color> colorMap;
	private int gunID;
	
	public GunPickup(int gunID, int x, int y, CentipedeComponent comp){
		super(x, y, comp);
		this.gunID = gunID;
		this.colorMap = new HashMap<Integer, Color>();
		this.colorMap.put(PISTOL_NUMBER, Color.BLACK);
		this.colorMap.put(SHOTGUN_NUMBER, Color.GRAY);
		this.colorMap.put(BOOMERANG_NUMBER, Color.WHITE);
	}
	
	@Override
	public Image getImage(){
		if(this.gunID == PISTOL_NUMBER){
			return Toolkit.getDefaultToolkit().getImage("src/Pistol.png");
		}
		if(this.gunID == SHOTGUN_NUMBER){
			return Toolkit.getDefaultToolkit().getImage("src/Shotgun.png");
		}
		return Toolkit.getDefaultToolkit().getImage("src/Boomerang.png");
	}
	
	@Override
	public Color getColor(){
		return this.colorMap.get(gunID);
	}
	
	public int getGunID(){
		return this.gunID;
	}
	
	@Override
	public void collide(Collidable collidable) {
		collidable.collideWithGunPickup(this);
	}
	
	@Override
	public void collideWithCharacter(PlayerCharacter c){
		this.die();
		c.changeGun(this.gunID);
	}

}
