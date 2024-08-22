import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
// import java.awt.event.ActionListener;

public class game extends JFrame
{
    JButton[] bt = new JButton[9];
    boolean xo = false;
    boolean[] click = new boolean[9];

    public game ()
    {
        //config widow
        setVisible(true); // visible window
        setTitle("Jogo da Velha");
        setDefaultCloseOperation(3); // exit x
        setLayout(null); // thats allow modification
        setBounds(700, 100, 700, 500);

        int count = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) 
            {
                bt[count] = new JButton();
                bt[count].setFont(new Font("arial", Font.BOLD, 40));
                add(bt[count]);
                bt[count].setBounds((100 * i) + 60 ,( 100 * j) + 60, 95, 95); // config width
                count++;
            }
        }

        for(int i = 0; i < 9; i++)
        {
            click[i] = false;
        }

        //[false, false, false]

        bt[0].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[0] == false)
                {
                    click[0] = true;
                    change(bt[0]);
                     //[true, false, false]
                     //ele só muda sd for falso, o que significa que nunca teve u clique nessa posição
                }
            }
        });

        bt[1].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[1] == false)
                {
                    click[1] = true;
                    change(bt[1]);
                }
            }
        });

        bt[2].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[2] == false)
                {
                    click[2] = true;
                    change(bt[2]);
                }
            }
        });

        bt[3].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[3] == false)
                {
                    click[3] = true;
                    change(bt[3]);
                }
            }
        });

        bt[4].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[4] == false)
                {
                    click[4] = true;
                    change(bt[4]);
                }
            }
        });

        bt[5].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[5] == false)
                {
                    click[5] = true;
                    change(bt[5]);
                }
            }
        });

        bt[6].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[6] == false)
                {
                    click[6] = true;
                    change(bt[6]);
                }
            }
        });

        bt[7].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[7] == false)
                {
                    click[7] = true;
                    change(bt[7]);
                }
            }
        });

        bt[8].addActionListener(new java.awt.event.ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                if(click[8] == false)
                {
                    click[8] = true;
                    change(bt[8]);
                }
            }
        });

    }

    //se verdadeiro x e se falso o
    //eele alterna entre falso e verdadeiro, toda vez que um clique acontece

    public void change(JButton btn)
    {
        if(xo){
            btn.setText("O");
            xo = false;
        }
        else{
            btn.setText("X");
            xo = true;
        }
    } // alternar 

    public static void main(String[] args) 
    {
        new game();
    }

}
