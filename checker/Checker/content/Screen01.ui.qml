/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
// import Checker

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    GridView {
        id: gridView
        x: 8
        y: 8
        width: 1904
        height: 1064
        delegate: Item {
            x: 5
            height: 50
            Column {
                spacing: 5
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    x: 5
                    text: name
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        cellWidth: 70
        cellHeight: 70

        ProgressBar {
            id: progressBar
            x: 0
            y: 928
            width: 1904
            height: 57
            value: 0.5
        }

        Switch {
            id: switch1
            x: 0
            y: 61
            text: qsTr("Enable sanitizer?")
        }

        Switch {
            id: switch2
            x: 0
            y: 107
            text: qsTr("Use testlib.h and SPJ for judging?")
        }

        Switch {
            id: switch3
            x: 0
            y: 153
            text: qsTr("Use Python as generator instead of C++?")
        }

        Switch {
            id: switch4
            x: 0
            y: 199
            text: qsTr("Stop when program get a incorrect response?")
        }

        Label {
            id: label
            x: 813
            y: 996
            width: 203
            height: 15
            text: qsTr("Copyleft 浙江省温岭中学 红豆蛋黄派")
            scale: 1
        }

        Label {
            id: label1
            x: 810
            y: 1010
            text: qsTr("Release under GNU GPL 3.0 License")
        }

        
        Switch {
            id: switch5
            x: 0
            y: 245
            text: qsTr("Use validator")
        }
        
        TextField {
            id: textField
            x: 0
            y: 292
            text: "Problem name"
            placeholderText: qsTr("Text Field")
        }
        
        SpinBox {
            id: spinBox
            x: 0
            y: 338
            value: 100
            to: 1000000
            from: 1
        }
        
        Label {
            id: label2
            x: 146
            y: 351
            text: qsTr("Test cases count")
        }

        Label {
            id: label4
            x: 146
            y: 451
            text: qsTr("Time Limit (ms)")
        }

        TextArea {
            id: textArea
            x: 800
            y: 6
            width: 1100
            height: 460
            placeholderText: qsTr("Text Area")
        }

        TextArea {
            id: textArea1
            x: 800
            y: 474
            width: 1100
            height: 460
            placeholderText: qsTr("Text Area")
        }

        Label {
            id: label3
            x: 146
            y: 398
            text: qsTr("Threads count")
        }

        SpinBox {
            id: spinBox2
            x: 0
            y: 439
            editable: true
            stepSize: 50
            to: 100000
            value: 1000
        }

        SpinBox {
            id: spinBox1
            x: 0
            y: 385
            editable: true
            to: 256
            from: 1
            value: 1
        }
    }
    
    

}
