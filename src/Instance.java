import java.awt.Color;
import java.awt.Image;
import java.awt.geom.Rectangle2D;



public abstract class Instance implements Moveable , Collidable{
	
	private final int BLOCK_SIZE = 20;
	private final int SPEED = 2;
	private final Color DEFAULT_COLOR = Color.RED;
	public final CentipedeComponent comp;
	public int x;
	public int y;
	public Rectangle2D.Double sprite;
	protected int BlockSIZE=20;
	
	public Instance(int x, int y,CentipedeComponent comp){
		this.comp=comp;
		this.x = x;
		this.y = y;
		this.sprite = new Rectangle2D.Double(x, y, BLOCK_SIZE, BLOCK_SIZE);
	}
	
	public boolean isInPlayerArea(){
		if(this.y > 600 && this.y < 900){
			if(this.x > 0 && this.x < 900){
				return true;
			}
		}
		return false;
	}
	
	public int getX(){
		return this.x;
	}
	
	public int getY(){
		return this.y;
	}
	
	public Image getImage(){
		return null;
	}
	
	public Rectangle2D.Double getSprite(){
		return this.sprite;
	}
	
	public void update(){
		this.sprite = new Rectangle2D.Double(this.x, this.y, BLOCK_SIZE, BLOCK_SIZE);
	}
	
	public java.awt.Color getColor(){
		return DEFAULT_COLOR;
	}
	public void die(){
		this.comp.removeinstance(this);
	}
	public String toString(){
		return "NOT A CENTIPEDE";
	}
	
	
	@Override
	public void moveUp() {
		this.y -= SPEED;
	}

	@Override
	public void moveRight() {
		this.x += SPEED;
	}

	@Override
	public void moveDown() {
		this.y += SPEED;
	}

	@Override
	public void moveLeft() {
		this.x -= SPEED;
	}
	public void collide(Collidable collidable) {
	}
	
	public void collideWithMushroom(Mushroom m) {
	}
	
	public void collideWithCharacter(PlayerCharacter c) {
	}
	
	public void collideWithBullet(Bullet b) {
	}
	
	public void collideWithCentipede(LinkedCentipede c){
	}
	
	public void collideWithShotgunShell(ShotgunShell s){
	}
	
	public void collideWithBoomerang(Boomerang b){
	}
	
	public void collideWithGunPickup(GunPickup g){
	}
	
	public void collideWithSpider(Spider s){
	}
	
	public void collideWithScorpion(Scorpion s){
	}
	
	public void collideWithFlea(Flea f){
	}
}
