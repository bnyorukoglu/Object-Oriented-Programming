/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw8;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.LineBorder;

/**
 *
 * @author bengi
 */
public final class ConnectFour {

    char start = 'A';
    ArrayList< ArrayList<Cell>> gameCells;
    private int width, height;
    private char harf;
    private char oyunSecimi, oyunTasi, sutun;
    private int satir;
    private JFrame frame;
    private JLabel[][] slots;
    private JButton[] buttons;
    private int flag;
    int kazanmaKontrol = 0, kazanmaKontrol2 = 0, kazanmaKontrol3 = 0;
    int tahtaDolumu = 0;

    public ConnectFour() {

        takeWidthAndHeight();
        playGame();
        startGui();
    }

    public final class Cell {

        private char position;
        private int row;
        private char cellInformation;

        public Cell(char sutun, int satir, char Information) {
            setPosition(sutun);
            setRow(satir);
            setInformation(Information);
        }

        public Cell() {

        }
        //getters

        public char getPosition() {
            return position;
        }

        public char getInformation() {
            return cellInformation;
        }

        public int getRow() {
            return row;
        }
        //setters

        public void setPosition(char pos) {
            position = pos;
        }

        public void setRow(int r) {
            row = r;
        }

        public void setInformation(char info) {
            cellInformation = info;
        }

    }

    public void setWidth(int genislik) {
        width = genislik;
    }

    public void setHeight(int yukseklik) {
        height = yukseklik;
    }

    public int getHarf() {
        return harf;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    private char getTas() {
        return oyunTasi;
    }

    private void setTas(char tas) {
        oyunTasi = tas;
    }

    private char getOyunSecimi() {
        return oyunSecimi;
    }

    private void setHarf(char h) {
        harf = h;
    }

    private void setSutun(char gelenSutun) {
        sutun = gelenSutun;
    }

    private void startGui() {

        flag = 1;
        frame = new JFrame("connect four");
        JPanel panel = (JPanel) frame.getContentPane();

        panel.setLayout(new GridLayout(height + 1, width));
        slots = new JLabel[height][height];
        buttons = new JButton[height];
        char baslangic = 'a';
        for (int i = 0; i < height; i++) {
            buttons[i] = new JButton("" + (i + 1));
            buttons[i].setActionCommand("" + i);
            buttons[i].setBackground(Color.lightGray);
            buttons[i].setForeground(Color.BLACK);
            buttons[i].setFont(new Font("Arial", Font.BOLD, 15));
            buttons[i].addActionListener(new followButton());
            panel.add(buttons[i]);
        }
        for (int column = 0; column < height; column++) {
            for (int row = 0; row < height; row++) {
                slots[row][column] = new JLabel();
                slots[row][column].setHorizontalAlignment(SwingConstants.CENTER);
                slots[row][column].setBorder(new LineBorder(Color.black));
                panel.add(slots[row][column]);
            }
        };
        frame.setContentPane(panel);
        frame.setSize(700, 600);
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    private class followButton implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            int a = Integer.parseInt(e.getActionCommand());
            sutun = (char) (a + 97);
            mainfunc();
            updateBoard();
            if (flag == 1) {
                flag = 0;
            } else {
                flag = 1;
            }

            if (kazanmaKontrol >= 4 || kazanmaKontrol2 >= 4 || kazanmaKontrol3 >= 4 || tahtaDolumu > getWidth() * getHeight()) {
                String kazanma = "Game Over";
                int n = JOptionPane.showConfirmDialog(frame, "NEW GAME?", kazanma,
                        JOptionPane.YES_NO_OPTION);
                if (n < 1) {
                    takeWidthAndHeight();
                    playGame();
                    startGui();

                } else {
                    frame.dispose();
                }
            }
        }
    }

    public void updateBoard() {
        for (int column = 0; column < height; column++) {
            for (int row = 0; row < height; row++) {
                if (gameCells.get(column).get(row).cellInformation == 'X'
                        || gameCells.get(column).get(row).cellInformation == 'O') {
                    if (gameCells.get(column).get(row).cellInformation == 'X') {
                        slots[row][column].setOpaque(true);
                        slots[row][column].setText("X");
                        slots[row][column].setForeground(Color.MAGENTA);
                    }
                    if (gameCells.get(column).get(row).cellInformation == 'O') {
                        slots[row][column].setOpaque(true);
                        slots[row][column].setText("O");
                        slots[row][column].setForeground(Color.DARK_GRAY);
                    }
                }
            }
        }
    }

    private void takeWidthAndHeight() {
        int gecici;

        String takeSize;
        //GENİSLİK ALMA VE KONTROL

        takeSize = JOptionPane.showInputDialog("Oyun alanının boyutunu giriniz ");
        gecici = Integer.parseInt(takeSize);
        setWidth(gecici);
        //cin ile kullanıcıdan bilgi alındıktan sonra enter'a basınca gelen new line karakterini yok say

        //girilen size'in saayi degerinin 4 ile 20 arasında olup olmadigina bakar
        //Eger bu aralikta degilse tekrar size ister
        while (gecici < 3 && gecici > 26) {
            takeSize = JOptionPane.showInputDialog("Oyun alanının boyutunu tekrar giriniz ");
            gecici = Integer.parseInt(takeSize);
        }
        setHeight(gecici);
    }

    private int isValid(char sutun) {
        int sayac = 0;
        char i = 'a';
        int k = 0;
        while (k < getWidth()) {
            if (sutun != i) {
                sayac++;
            }
            ++k;
            ++i;
        }
        if (sayac == getWidth()) {
            if (getHarf() != 'a') {

                System.err.println("Girdiginiz sutun hatali.Tekrar giriniz.");
            }
            return 0;
        } else {
            return 1;
        }

    }

    public void displayBoard() {
        int i, m;
        char bas;
        System.out.print(" ");

        for (int a = 0; a < getWidth(); ++a) {
            bas = (char) ('a' + a);
            System.out.printf("%c ", bas);

        }
        System.out.println(" ");
        for (i = 0; i < getHeight(); ++i) {
            for (m = 0; m < getWidth(); ++m) {
                System.out.printf(" %c", gameCells.get(i).get(m).getInformation());
            }
            System.out.println(" ");

        }
    }

    private int satirHesapla(char sutun) {
        int satir = 0, i = 0;
        int tut = sutun;
        tut -= 97;
        while (i < getHeight()) {

            if (gameCells.get(i).get(tut).getInformation() == ' ') {
                satir = satir + 1;
            }
            ++i;
        }
        return satir;
    }

    private int konulanTasinSatiriniHesapla(char sutun) {
        int satir = 0, i = 0;
        int tut = sutun;
        tut -= 97;
        while (gameCells.get(i).get(tut).getInformation() == ' ' && i < getHeight()) {
            satir = satir + 1;
            ++i;
        }
        return satir;
    }

    private int movPlayerX(char sutun) {

        int satir;
        int tut = sutun;
        tut -= 97; //a=0,b=1,c=2...girilen sutunun degerini bulmamızı saglar

        if (isValid(sutun) == 1) {
            satir = satirHesapla(sutun);
            satir = satir - 1;
            if (satir < 0) {
                satir = 0;
            }
            if (gameCells.get(satir).get(tut).getInformation() == ' ') {//gidilmek istenen yer bos ise X konur
                gameCells.get(satir).get(tut).setInformation('X');
                //gameCells[satir][tut].setInformation('X');
                displayBoard();
                return 1;
            } else {//gidilmek istenen yer dolu ise hata verir
                System.out.println("Girdiğiniz alan dolu baska bir sütun giriniz!");
                return 0;
            }
        }
        return 0;
    }

    private int movPlayerO(char sutun) {
        int satir;
        int tut = sutun;
        tut -= 97; //a=0,b=1,c=2...girilen sutunun degerini bulmamızı saglar
        if (isValid(sutun) == 1) {

            satir = satirHesapla(sutun);
            satir = satir - 1;
            if (satir < 0) {
                satir = 0;
            }
            if (gameCells.get(satir).get(tut).getInformation() == ' ') {
                gameCells.get(satir).get(tut).setInformation('O');

                displayBoard();
                return 1;
            } else {//gidilmek istenen yer dolu ise hata verir.
                //Buradaki a benim kendi belirledigim bir harf.
                //Computera karsi oynandiginda parametreye a geliyor ve asagidaki
                //masajin engellenmesi saglaniyor.
                if (getHarf() != 'a') {
                    System.out.println("Girdiğiniz alan dolu baska bir sütun giriniz!");
                }

                return 0;
            }
        }
        return 0;
    }

    private int yatayKontrolO(char sutun) {

        int toplamBuldum = 0, buldum = 0;
        int flag = 0;

        int tut = sutun;
        tut -= 97;
        int satir = konulanTasinSatiriniHesapla(sutun);

        for (int i = 0; i < getWidth() && flag == 0; ++i) {

            if (gameCells.get(satir).get(i).getInformation() == 'O') {

                buldum = buldum + 1;
                if (buldum > toplamBuldum) {
                    toplamBuldum = buldum;
                }
                //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
                if (toplamBuldum == 4) {

                    if (getHarf() == 'a') {
                        System.out.println("Bilgisayar oyunu kazandı");

                    } else {
                        System.out.println("Oyuncu O kazandı");

                    }
                    System.out.println("KAZANMA DURUMU");

                    displayBoard();
                    flag = 1;
                }
            } else {
                buldum = 0;
            }
        }
        return toplamBuldum;
    }

    private int yatayKontrolX(char sutun) {

        int toplamBuldum = 0, buldum = 0;
        int flag = 0;
        int tut = sutun;
        tut -= 97;
        int satir = konulanTasinSatiriniHesapla(sutun);

        for (int i = 0; i < getWidth() && flag == 0; ++i) {

            if (gameCells.get(satir).get(i).getInformation() == 'X') {

                buldum = buldum + 1;
                if (buldum > toplamBuldum) {
                    toplamBuldum = buldum;
                }
                //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
                if (toplamBuldum == 4) {

                    System.out.println("Oyuncu X kazandı");

                    System.out.println("KAZANMA DURUMU");

                    displayBoard();
                    flag = 1;
                }
            } else {
                buldum = 0;
            }
        }
        return toplamBuldum;
    }

    private int dikeyKontrolX(char sutun) {

        int toplamBuldum = 0, buldum = 0, tasKucult = 0;
        int flag = 0;
        int tut = sutun;
        tut -= 97;

        for (int i = 0; i < getHeight() && flag == 0; ++i) {

            if (gameCells.get(i).get(tut).getInformation() == 'X') {

                buldum = buldum + 1;
                if (buldum > toplamBuldum) {
                    toplamBuldum = buldum;
                }
                //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
                if (toplamBuldum == 4) {
                    System.out.println("Oyuncu X kazandı");
                    System.out.println("KAZANMA DURUMU");

                    displayBoard();
                    flag = 1;
                }
            } else {
                buldum = 0;
                tasKucult = 0;
            }
        }
        return toplamBuldum;
    }

    private int dikeyKontrolO(char sutun) {
        int toplamBuldum = 0, buldum = 0;
        int flag = 0;
        int tut = sutun;
        tut -= 97;
        for (int i = 0; i < getHeight() && flag == 0; ++i) {
            if (gameCells.get(i).get(tut).getInformation() == 'O') {

                buldum = buldum + 1;
                if (buldum > toplamBuldum) {
                    toplamBuldum = buldum;
                }
                //4 tane X'in bulundugu yerlerdeki X ler kucuk x e donusturulur.
                if (toplamBuldum == 4) {

                    if (getHarf() == 'a') {
                        System.out.println("Bilgisayar oyunu kazandı");

                    } else {
                        System.out.println("Oyuncu O kazandı");

                    }
                    System.out.println("KAZANMA DURUMU");

                    displayBoard();
                    flag = 1;
                }
            } else {
                buldum = 0;
            }
        }
        return toplamBuldum;
    }

    private int caprazKontroller(int satir, char sutun, char oyuncuTasi) {
        int sutunSayisi = sutun - 97;
        int baslangicSatir = 0, baslangicSatir2 = 0;
        int baslangicSutun, baslangicSutun2;

        int bitisSatir, bitisSatir2;
        int bitisSutun, bitisSutun2;

        int dortEslesme = 0, eslesme1 = 0, eslesme2 = 0;

        int geciciSatir = satir;
        int geciciSutun = sutunSayisi;

        while (geciciSatir < getHeight() && geciciSutun < getWidth()) {
            geciciSutun = geciciSutun + 1;
            geciciSatir = geciciSatir + 1;
        }
        bitisSutun = geciciSutun - 1;
        bitisSatir = geciciSatir - 1;

        geciciSatir = satir;
        geciciSutun = sutunSayisi;
        while (geciciSatir >= 0 && geciciSutun >= 0) {
            geciciSatir = geciciSatir - 1;
            geciciSutun = geciciSutun - 1;
        }
        baslangicSatir = geciciSatir + 1;
        baslangicSutun = geciciSutun + 1;

        for (int i = baslangicSatir, j = baslangicSutun; i <= bitisSatir && j <= bitisSutun; ++i, ++j) {
            if (gameCells.get(i).get(j).getInformation() == 'X') {
                dortEslesme = dortEslesme + 1;
                if (dortEslesme > eslesme1) {

                    eslesme1 = dortEslesme;
                }
            } else {
                dortEslesme = 0;
            }
        }

        dortEslesme = 0;
        geciciSatir = satir;
        geciciSutun = sutunSayisi;
        while (geciciSatir >= 0 && geciciSutun < getWidth()) {
            geciciSutun = geciciSutun + 1;
            geciciSatir = geciciSatir - 1;
        }
        baslangicSatir2 = geciciSatir + 1;
        baslangicSutun2 = geciciSutun - 1;

        geciciSatir = satir;
        geciciSutun = sutunSayisi;
        while (geciciSatir < getHeight() && geciciSutun >= 0) {
            geciciSatir = geciciSatir + 1;
            geciciSutun = geciciSutun - 1;
        }
        bitisSutun2 = geciciSutun + 1;
        bitisSatir2 = geciciSatir - 1;

        for (int i = baslangicSatir2, j = baslangicSutun2; i <= bitisSatir2 && j >= bitisSutun2; ++i, --j) {
            if (gameCells.get(i).get(j).getInformation() == oyuncuTasi) {

                dortEslesme = dortEslesme + 1;
                if (dortEslesme > eslesme2) {

                    eslesme2 = dortEslesme;
                }
            } else {
                dortEslesme = 0;
            }
        }

        if (eslesme1 > eslesme2) {
            if (eslesme1 >= 4) {

                System.out.printf("Oyuncu  %c kazandı", oyuncuTasi);
                System.out.println("");
                System.out.println("KAZANMA DURUMU");

                displayBoard();
            }
            return eslesme1;

        } else {
            if (eslesme2 >= 4) {

                System.out.printf("Oyuncu  %c kazandı", oyuncuTasi);
                System.out.println("");
                System.out.println("KAZANMA DURUMU");
                displayBoard();
            }
            return eslesme2;
        }
    }

    int movPlayerComputer(char sutun, int satir) {

        setHarf('a');
        int yataySayi, dikeySayi, caprazSayi;

        int sayiyaCevir = sutun - 97;
        System.out.println("sayiya: " + sayiyaCevir);
        int boslukAlan = (getWidth() - 1) - sayiyaCevir;
        int bilgisayarHamle = 0, hamle;

        yataySayi = yatayKontrolX(sutun);
        dikeySayi = dikeyKontrolX(sutun);
        caprazSayi = caprazKontroller(satir, sutun, 'O');
        do {
            if (boslukAlan == 0) {
                hamle = 1;
                while (bilgisayarHamle == 0) {
                    bilgisayarHamle = movPlayerO((char) (sutun - hamle));
                    if (hamle == getWidth()) {
                        bilgisayarHamle = 1;
                    }
                    ++hamle;
                }
            } else if (yataySayi == 2 || yataySayi == 3) {
                bilgisayarHamle = movPlayerO((char) (sutun + 1));
                hamle = -getWidth();
                while (bilgisayarHamle == 0) {
                    bilgisayarHamle = movPlayerO((char) (sutun + hamle));
                    if (hamle == getWidth()) {
                        bilgisayarHamle = 1;
                    }
                    ++hamle;
                }
            } else if (dikeySayi == 2 || dikeySayi == 3) {
                bilgisayarHamle = movPlayerO(sutun);
                hamle = getWidth();
                while (bilgisayarHamle == 0) {
                    bilgisayarHamle = movPlayerO((char) (sutun - hamle));
                    if (hamle == -getHeight()) {
                        bilgisayarHamle = 1;
                    }
                    --hamle;
                }
            } else if (caprazSayi == 2 || caprazSayi == 3) {
                bilgisayarHamle = movPlayerO((char) (sutun - 1));
                hamle = -getWidth();
                while (bilgisayarHamle == 0) {
                    bilgisayarHamle = movPlayerO((char) (sutun + hamle));
                    if (hamle == getWidth()) {
                        bilgisayarHamle = 1;
                    }
                    ++hamle;
                }
            } else {
                hamle = -getWidth();
                while (bilgisayarHamle == 0) {
                    bilgisayarHamle = movPlayerO((char) (sutun + hamle));
                    if (hamle == getWidth()) {
                        bilgisayarHamle = 1;
                    }
                    ++hamle;
                }
            }
        } while (bilgisayarHamle == 0);
        return 1;
    }

    public void mainfunc() {

        int satir = 0;
        int kontrol, kontrol1, kontrol2;

        //Buradaki do whileda oyun baslar ve kazanmaKontrol,kazanmaKontrol2,kazanma
        //kontrol3 4ten kucuk oldukca devam eder.yani herhangi istenen bir sekilde
        //yan yana 4 saglanmadikca hicbir oyuncu kazanamaz ve hamle istenir.
        switch (oyunSecimi) {
            case 'C'://Bilgisayar ile oynamak istiyorsak
                if (flag == 1) {
                    oyunTasi = 'X';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    //oyuncu oyun alani disinda bir sutun girdiginde tekrar
                    //tekrar soracak

                    kontrol1 = movPlayerX(sutun);

                    kazanmaKontrol = yatayKontrolX(sutun);
                    kazanmaKontrol2 = dikeyKontrolX(sutun);

                    satir = satirHesapla(sutun);

                    kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                    flag = 0;
                }
                if (flag == 0) {
                    oyunTasi = 'O';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    do {

                        kontrol2 = movPlayerComputer(sutun, satir);

                        kontrol = yatayKontrolO(sutun);
                        if (kontrol > kazanmaKontrol) {
                            kazanmaKontrol = kontrol;
                        }

                        kontrol = dikeyKontrolO(sutun);
                        if (kontrol > kazanmaKontrol2) {
                            kazanmaKontrol2 = kontrol;
                        }

                        satir = satirHesapla(sutun);

                        kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                        if (kontrol > kazanmaKontrol3) {
                            kazanmaKontrol3 = kontrol;
                        }
                    } while (kontrol2 == 0);
                    //yanlis hamle yaparsa dongu tekrar doner
                }
                break;

            case 'P':
                if (flag == 1) {
                    oyunTasi = 'X';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    //oyuncu oyun alani disinda bir sutun girdiginde tekrar
                    //tekrar soracak
                    kontrol1 = movPlayerX(sutun);
                    kazanmaKontrol = yatayKontrolX(sutun);
                    kazanmaKontrol2 = dikeyKontrolX(sutun);
                    satir = satirHesapla(sutun);
                    kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);

                } else if (flag == 0) {
                    oyunTasi = 'O';
                    //buradaki flag karsilikli oynamayi saglar.
                    //X iken 1 ,sira O'ya gectiginde 0 olur
                    kontrol2 = movPlayerO(sutun);
                    kazanmaKontrol = yatayKontrolO(sutun);
                    kazanmaKontrol2 = dikeyKontrolO(sutun);
                    satir = satirHesapla(sutun);
                    kazanmaKontrol3 = caprazKontroller(satir, sutun, oyunTasi);
                }
                break;
        }
    }

    private void playGame() {
        flag = 1;
        String oyuncuAl;
        gameCells = new ArrayList<>();

        for (int i = 0; i < getHeight(); ++i) {

            ArrayList<Cell> gecici = new ArrayList<>();

            for (int m = 0; m < getWidth(); ++m) {
                Cell yuklenecekGecici = new Cell((char) i, m, ' ');
                gecici.add(yuklenecekGecici);
            }

            gameCells.add(gecici);
        }
        oyuncuAl = JOptionPane.showInputDialog("Bilgisar ile oynamak icin : C\n Karşılıklı oynamak için   : P");
        oyunSecimi = oyuncuAl.charAt(0);

        //Eger kucuk a veya kucuk z varsa buyuk harfe cevirir kontrollerin
        //daha kolay yapilabilmesi icin
        if (oyunSecimi >= 'a' && oyunSecimi <= 'z') {
            oyunSecimi = (char) (oyunSecimi - 32);
        } //istenen karakter haricinde bir secim yaildiysa hata verir ve tekrar ister
        while (!(oyunSecimi == 'C' || oyunSecimi == 'P')) {
            oyuncuAl = JOptionPane.showInputDialog("Yanlış oyun seçimi tekrar seçim yapınız!\n Bilgisar ile oynamak icin : C\n Karşılıklı oynamak için   : P");
            oyunSecimi = oyuncuAl.charAt(0);
            if (oyunSecimi >= 'a' && oyunSecimi <= 'z') {
                oyunSecimi = (char) (oyunSecimi - 32);
            }
        }
    }
}
