import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.Rectangle2D;
import java.util.Random;



public class Flea extends Instance {
	
	private final int MOVEMENT_SPEED = 1;
	private final Color FLEA_COLOR = Color.CYAN;
	
	private int MushroomTimer;
	private CentipedeComponent comp;
	
	public Flea(int x, int y, CentipedeComponent comp){
		super(x, y, comp);
		this.comp = comp;
		Random rand = new Random();
		this.MushroomTimer = rand.nextInt(80);
	}
	
	@Override
	public void update(){
		if(this.y < 900){
			this.y += MOVEMENT_SPEED;
		}
		else{
			this.die();
		}
		if(this.MushroomTimer >= 90){
			this.comp.addInstanceToAdd(new Mushroom(this.x, this.y, this.comp));
			this.MushroomTimer = 0;
		}
		this.MushroomTimer++;
		this.sprite = new Rectangle2D.Double(this.x, this.y, 20, 20);
	}
	
	@Override
	public Image getImage(){
		return Toolkit.getDefaultToolkit().getImage("src/Flea.png");
	}
	
	@Override
	public Color getColor(){
		return FLEA_COLOR;
	}
	
	@Override
	public void collideWithCharacter(PlayerCharacter c){
		c.hitByEnemy();
	}
	
	@Override
	public void collideWithBullet(Bullet b){
		this.comp.getCharacter().addScore(10);
		b.die();
		this.die();
	}
	
	@Override
	public void collideWithShotgunShell(ShotgunShell s){
		this.comp.getCharacter().addScore(10);
		s.die();
		this.die();
	}
	
	@Override
	public void collideWithBoomerang(Boomerang b){
		this.comp.getCharacter().addScore(10);
		b.die();
		this.die();
	}

}
