import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    id: root

    width  : 700
    height : 400
    
    visible: true

    signal loadMore()
    signal selectContact(int index)

    Loader {
        anchors.fill: parent
        
        source      : root.width > 500 ? "qml/SideView.qml" : "qml/StackedView.qml"
        
        onLoaded    : signalConnections.target = item
    }

    Connections {
        id                  : signalConnections
        
        ignoreUnknownSignals: true
        
        onLoadMore          : root.loadMore()
        onSelectContact     : root.selectContact(index)
    }
}
