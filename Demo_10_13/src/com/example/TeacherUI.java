package com.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class TeacherUI extends JFrame {
    private final JLabel codeLabel;
    private final JButton generateButton;
    private final JButton setDeadlineButton;
    private final JTextField deadlineField;

    public TeacherUI() {
        setTitle("教师端");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // 创建界面元素
        codeLabel = new JLabel("点击生成签到码");
        generateButton = new JButton("生成");
        setDeadlineButton = new JButton("设置截止时间");
        deadlineField = new JTextField();
        // 添加界面元素到面板
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 1));
        panel.add(codeLabel);
        panel.add(generateButton);
        panel.add(deadlineField);
        panel.add(setDeadlineButton);
        add(panel);
        // 添加生成签到码按钮的点击事件处理
        generateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String code = generateCode();
                codeLabel.setText(code);
            }
        });
        // 添加设置截止时间按钮的点击事件处理
        setDeadlineButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String deadline = deadlineField.getText();
                // 在这里可以将截止时间保存到数据库或其他地方
                JOptionPane.showMessageDialog(null, "截止时间已设置为：" + deadline);
            }
        });
    }

    private String generateCode() {
        // 在这里可以根据需要生成签到码
        Random random = new Random();
        int code = random.nextInt(10000);
        return String.format("%04d", code);
    }
//    public static void main(String[] args) {
//        SwingUtilities.invokeLater(new Runnable() {
//            @Override
//            public void run() {
//                new TeacherUI().setVisible(true);
//            }
//        });
//    }
}
