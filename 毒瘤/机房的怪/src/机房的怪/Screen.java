package 机房的怪;

import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.Vector;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Screen extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1695056764284262369L;
	private MyPanel mp;
    private Color rectColor = new Color(255,255,255);
    public void init(){
        Container p = getContentPane();
        mp=new MyPanel();
        this.add(mp);
        setBounds(100, 100, 1000, 600);
        setVisible(true);
        p.setBackground(rectColor);
        setResizable(true);
        this.addMouseListener(mp);
        this.addMouseMotionListener(mp);
        this.addMouseWheelListener(mp);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("机房的怪");
    }
	public void repaint() {
		mp.repaint();
	}
}
class MyPanel extends JPanel implements MouseListener,MouseMotionListener,MouseWheelListener{

	/**
	 * 
	 */
	private static final long serialVersionUID = -138922725021749195L;
	private static Vector<Color> msgColor=new Vector<Color>();
	private static Vector<Integer> msgtab=new Vector<Integer>();
	private static Vector<String> msgs=new Vector<String>();
	private static Vector<Long> msgt=new Vector<Long>();
	private static boolean repaintAble=true;
    public void paint(Graphics g){
    	if(!repaintAble)return;
        super.paint(g);
    	int width=g.getClipBounds().width;
        Long nowTime=java.time.Clock.systemUTC().millis();
        int textH=0;
        int ycnt=0;
        for(int i=0;i<msgs.size();i++) if(nowTime>msgt.get(i)){
        	textH+=20;
        	g.setColor(msgColor.get(i));
        	g.drawString(msgs.get(i), width*3/8+msgtab.get(i), textH);
        	ycnt++;
        }
        GameMain.a.print(0,0,g,true);
        GameMain.b.print(width*2/3,0,g,false);
        while(ycnt>20) {
        	msgColor.remove(0);
        	msgtab.remove(0);
        	msgs.remove(0);
        	msgt.remove(0);
        	ycnt--;
        }
    }
	@Override
	public void mouseWheelMoved(MouseWheelEvent arg0) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mouseDragged(MouseEvent arg0) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO 自动生成的方法存根
		
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		repaintAble=false;
		GameMain.a.setLastHp();
		GameMain.b.setLastHp();
		GameMain.a.attack();
		GameMain.b.attack();
		GameMain.a.testAlive();
		GameMain.b.testAlive();
		repaintAble=true;
	}
}
