import QtQuick 2.0

Row {
    id     : root
    
    height : 10
    
    enabled: visible

    readonly property var _COLORS: [
        "blue",
        "green",
        "cyan",
        "red",
        "purple"
    ]

    resources: [
        Timer {
            id                      : timer
            
            property int currentRect: 0
            
            interval                : 250
            running                 : root.enabled
            repeat                  : true
            
            onTriggered             : currentRect = (currentRect+1) % _COLORS.length
        }
    ]

    Repeater {
        model: _COLORS.length

        Rectangle {
            width                 : 20
            height                : index === timer.currentRect ? 10 : 5
            
            anchors.verticalCenter: parent.verticalCenter
            
            color                 : _COLORS[index]
            
            opacity               : 0.5

            Behavior on height { NumberAnimation {} }
        }
    }
}
