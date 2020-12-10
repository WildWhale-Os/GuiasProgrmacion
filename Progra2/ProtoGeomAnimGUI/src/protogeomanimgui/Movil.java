/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package protogeomanimgui;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author tomasb
 */
public class Movil {
    private int x,y;
    public Movil(int x, int y){
        this.x = x;
        this.y = y;
    }
    public void paint (Graphics g){
        g.setColor(Color.red);
        g.fillRect(x, y,60,50);
    }
    
    public void mover(){
        x++;
    }
}
