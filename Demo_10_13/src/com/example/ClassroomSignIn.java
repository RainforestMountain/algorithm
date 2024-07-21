package com.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;

public class ClassroomSignIn {
    private final JFrame frame;
    private final JLabel label;
    private final JTextField codeTextField;
    private final JButton signInButton;

    public ClassroomSignIn() {
        frame = new JFrame("课堂签到");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        label = new JLabel("请输入签到码：");

        codeTextField = new JTextField(10);

        signInButton = new JButton("签到");
        signInButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String code = codeTextField.getText();

                if (code.isEmpty()) {
                    JOptionPane.showMessageDialog(frame, "请输入签到码！");
                    return;
                }

                // 这里是签到操作的代码
                boolean success = performSignIn(code);

                if (success) {
                    JOptionPane.showMessageDialog(frame, "签到成功！");
                } else {
                    JOptionPane.showMessageDialog(frame, "签到失败！请检查签到码是否正确。");
                }
            }
        });

        frame.setLayout(new FlowLayout());
        frame.add(label);
        frame.add(codeTextField);
        frame.add(signInButton);

        frame.setVisible(true);
    }

    private boolean performSignIn(String code) {
        try {
            // 获取当前时间
            LocalDateTime currentTime = LocalDateTime.now();

            // 将签到记录写入文件
            FileWriter writer = new FileWriter("data.txt", true);
            writer.write("签到时间：" + currentTime + " 签到码：" + code + "\n");
            writer.close();

            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

//    public static void main(String[] args) {
//        SwingUtilities.invokeLater(new Runnable() {
//            @Override
//            public void run() {
//                new ClassroomSignIn();
//            }
//        });
//    }
}
