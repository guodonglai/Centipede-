import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.Rectangle2D;


public class Spider extends Instance {
	
	private final Color SPIDER_COLOR = Color.PINK;
	private final int MOVEMENT_SPEED = 2;
	
	private int movingSide;
	private int movingUp;
	
	public Spider(int x, int y, CentipedeComponent comp){
		super(x, y, comp);
		this.movingSide = 1;
		this.movingUp = -1;
	}
	
	@Override
	public void update(){
		this.x += MOVEMENT_SPEED * this.movingSide;
		this.y += MOVEMENT_SPEED * this.movingUp;
		this.sprite = new Rectangle2D.Double(this.x, this.y, 20, 20);
		if(this.x >= 880 || this.x <= 20){
			this.movingSide *= -1;
		}
		if(this.y >= 880 || this.y <= 600){
			this.movingUp *= -1;
		}
	}
	
	@Override
	public Image getImage(){
		return Toolkit.getDefaultToolkit().getImage("src/Spider.png");
	}
	
	@Override
	public String toString(){
		return "SPIDER";
	}
	
	@Override
	public Color getColor(){
		return SPIDER_COLOR;
	}
	
	@Override
	public void collide(Collidable c){
		c.collideWithSpider(this);
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
