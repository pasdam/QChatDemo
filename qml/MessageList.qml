import QtQuick 2.5

ListView {
    id: root

    readonly property var _COLORS: [
        "blue",
        "green",
        "red",
        "purple",
        "cyan"
    ]

    signal loadMore()

    Component.onCompleted: positionViewAtEnd()

    // "Load more" management
    property int startingY: 0
    onDraggingChanged     : startingY = contentY
    onMovementEnded       : if (contentY === 0 && startingY < -20) root.loadMore()
    
    // context model
    model                 : messageModel
    
    // section used to group message by sender
    section.property      : "fullName"

    Spinner {
        id                      : spinner
        
        anchors.horizontalCenter: parent.horizontalCenter
        
        visible                 : root.model.loading
    }

    delegate: Column {
        anchors.left : isMySelf ? parent.left : undefined
        anchors.right: isMySelf ? undefined   : parent.right

        readonly property string previousSection: ListView.previousSection

        Text {
            id               : userLabel
            
            anchors.left     : isMySelf ? parent.left : undefined
            anchors.right    : isMySelf ? undefined   : parent.right
            
            verticalAlignment: Text.AlignVCenter
            
            color            : "gray"
            
            text             : parent.previousSection === fullName ? "" : fullName
        }

        Text {
            id               : timestampLabel
            
            anchors.left     : isMySelf ? parent.left : undefined
            anchors.right    : isMySelf ? undefined   : parent.right
            
            verticalAlignment: Text.AlignVCenter
            
            color            : "gray"
            
            text             : new Date(timestamp*1000).toLocaleString(Qt.locale(), "dd-MM-yyyy, hh:mm")
        }

        Text {
            id               : messageLabel
            
            anchors.left     : isMySelf ? parent.left : undefined
            anchors.right    : isMySelf ? undefined   : parent.right
            
            verticalAlignment: Text.AlignVCenter
            
            font.pixelSize   : 20
            
            text             : message
        }
    }

    displaced: Transition { NumberAnimation { properties: "y"; easing.type: Easing.OutQuart; duration: 250 } }
}
