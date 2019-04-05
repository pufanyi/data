package 机房的怪;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class GameMain {
	public static Scanner cin=new Scanner(System.in);
	public static Screen screen=new Screen();
	public static Master a,b;
	@SuppressWarnings("resource")
	public static void main(String[] args) {
		String usa,usb;
    	Scanner fin;
    	try {
			fin=new Scanner(new File("./general.ini"));
			usa=fin.nextLine();
			usb=fin.nextLine();
		} catch (FileNotFoundException e) {
			System.out.println("应用找不到关键文件\"general.ini\"。");
			usa="mj";
			usb="yk";
		}
		a=new Master(usa);
		b=new Master(usb);
		a.set(b);
		b.set(a);
		screen.init();
		while(true) {
			screen.repaint();
		}
	}

}
