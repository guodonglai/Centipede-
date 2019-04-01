import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.Rectangle2D;


public class Scorpion extends Instance {
	
	private final int MOVEMENT_SPEED = 2;
	private final Color SCORPION_COLOR = Color.RED;
	
	private int direction;
	
	public Scorpion(int x, int y, CentipedeComponent comp){
		super(x, y, comp);
		this.direction = -1;
	}
	
	@Override
	public void update(){
		if(this.x <= 0 || this.x >= 900){
			this.direction *= -1;
		}
		this.x += MOVEMENT_SPEED*this.direction;
		this.sprite = new Rectangle2D.Double(this.x, this.y, 20, 20);
	}
	
	@Override
	public Image getImage(){
		return Toolkit.getDefaultToolkit().getImage("src/Scorpion.png");
	}
	
	@Override
	public Color getColor(){
		return SCORPION_COLOR;
	}
	
	@Override
	public String toString(){
		return "Scorpion";
	}
	
	@Override
	public void collide(Collidable c){
		c.collideWithScorpion(this);
	}
	
	@Override
	public void collideWithBullet(Bullet b){
		this.comp.getCharacter().addScore(5);
		b.die();
		this.die();
	}
	
	@Override
	public void collideWithShotgunShell(ShotgunShell s){
		this.comp.getCharacter().addScore(5);
		s.die();
		this.die();
	}
	
	@Override
	public void collideWithBoomerang(Boomerang b){
		this.comp.getCharacter().addScore(5);
		b.die();
		this.die();
	}
	
	@Override
	public void collideWithCharacter(PlayerCharacter c){
		c.hitByEnemy();
	}

}
