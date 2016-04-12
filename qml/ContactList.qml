import QtQuick 2.0

ListView {
    id: root

    signal selectContact(int index)

    readonly property var _COLORS: [
        "blue",
        "green",
        "red",
        "purple",
        "cyan"
    ]

    model: contactsModel

    // by default no row should be selected
    Component.onCompleted: currentIndex = -1
    onModelChanged       : currentIndex = -1

    delegate: MouseArea {
        width : root.width
        height: 50
        
        clip  : true

        onClicked: {
            if (root.currentIndex !== index) {
                root.currentIndex = index
                root.selectContact(index)

            } else {
                root.currentIndex = -1
            }
        }

        Rectangle {
            width       : root.currentIndex == index ? parent.width : 4
            height      : parent.height
            
            color       : "transparent"
            
            border.width: 2
            border.color: root._COLORS[index % root._COLORS.length]
            
            opacity     : 0.5
        }

        Text {
            width            : parent.width - 14
            height           : parent.height
            
            anchors.right    : parent.right
            
            verticalAlignment: Text.AlignVCenter
            
            text             : display
        }
    }
}
