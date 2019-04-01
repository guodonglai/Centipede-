import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.Rectangle2D;


public class Boomerang extends Instance {
	
	private static final int BOOMERANG_SPEED = 5;
	private final Color BOOMERANG_COLOR = Color.YELLOW;
	private final int BOOMERANG_SIZE = 15;
	private final int RETURN_TIME = 100;
	
	private int timer;
	private PlayerCharacter player;


	public Boomerang(PlayerCharacter player, int x, int y,CentipedeComponent comp) {
		super(x, y, comp);
		this.timer = 0;
		this.player = player;
	}
	
	@Override
	public void update(){
		if(this.timer < RETURN_TIME){
			this.y -= BOOMERANG_SPEED;
			this.timer ++;
		}
		else{
			if(Math.abs(this.x - this.player.getX()) < BOOMERANG_SPEED){
				this.x = this.player.getX();
			}
			else{
				int sign = (int) Math.signum(this.player.getX() - this.x);
				this.x += sign*BOOMERANG_SPEED;
			}
			this.y += BOOMERANG_SPEED;
			if(this.sprite.intersects(this.player.getSprite())){
				this.die();
			}
		}
		this.sprite = new Rectangle2D.Double(this.x, this.y, BOOMERANG_SIZE, BOOMERANG_SIZE);
	}
	
	@Override
	public Color getColor(){
		return BOOMERANG_COLOR;
	}
	
	@Override
	public void collide(Collidable collidable) {
		collidable.collideWithBoomerang(this);
		
	}
	
	@Override
	public void collideWithCentipede(LinkedCentipede c){
		c.die();
		this.die();
	}
	
	@Override
	public void collideWithSpider(Spider s){
		s.die();
		this.die();
	}
	
	@Override
	public Image getImage(){
		return Toolkit.getDefaultToolkit().getImage("src/Boomerang.png");
	}
	
	@Override
	public void collideWithScorpion(Scorpion s){
		s.die();
		this.die();
	}
	
	@Override
	public void collideWithFlea(Flea f){
		f.die();
		this.die();
	}

}
