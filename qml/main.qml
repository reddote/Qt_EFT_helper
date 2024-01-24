import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 400
    height: 300

    TableView {
        anchors.fill: parent
        model: myBulletTableModel //C++ model instance

        TableViewColumn {
            title: "Row Name"
            role: "display"  // The role name 
            // Note: In QtQuick.Controls 1.x, TableViewColumn is not directly editable
        }
    }
}
