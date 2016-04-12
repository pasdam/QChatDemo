import QtQuick 2.5
import QtQuick.Controls 1.4

StackView {
    id: root

    signal selectContact(int index)
    signal loadMore()
    
    initialItem                          : contactList
    
    property int currentState            : _STATE_CONTACTS
    
    readonly property int _STATE_CONTACTS: 0
    readonly property int _STATE_MESSAGES: _STATE_CONTACTS + 1

    states: [
        State {
            when: root.currentState === root._STATE_CONTACTS
            StateChangeScript { script: root.pop() }
        },
        State {
            when: root.currentState === root._STATE_MESSAGES
            StateChangeScript { script: root.push({item: messageListContainer/*, replace: true*/}) }
        }
    ]

    ContactList {
        id             : contactList
        
        width          : root.width
        height         : root.height
        
        visible        : false
        
        onSelectContact: {
            root.currentState = root._STATE_MESSAGES
            root.selectContact(index)
        }
    }

    Item {
        id     : messageListContainer
        
        width  : root.width
        height : root.height
        
        visible: false

        MouseArea {
            id       : backButton
            
            width    : parent.width
            height   : 50
            
            onClicked: root.currentState = root._STATE_CONTACTS

            Text {
                height            : parent.height
                
                anchors.left      : parent.left
                anchors.leftMargin: 10
                anchors.right     : parent.right
                
                verticalAlignment : Text.AlignVCenter
                
                font.pixelSize    : height * 0.5
                
                text              : "< " + qsTr("Contact list")
            }
        }

        MessageList {
            anchors.fill       : parent
            anchors.topMargin  : backButton.height
            anchors.leftMargin : 10
            anchors.rightMargin: anchors.leftMargin
            
            onLoadMore         : root.loadMore()
        }
    }

    delegate: StackViewDelegate {
        function transitionFinished(properties) {
            properties.exitItem.x = 0
        }

        pushTransition: StackViewTransition {
            PropertyAnimation { target: enterItem ; property: "x" ; from: enterItem.width ; to: 0               ; duration: 300 ; easing.type: Easing.InQuad }
            PropertyAnimation { target: exitItem  ; property: "x" ; from: 0               ; to: -exitItem.width ; duration: 300 ; easing.type: Easing.InQuad }
        }

        popTransition: StackViewTransition {
            PropertyAnimation { target: enterItem ; property: "x" ; easing.type: Easing.OutQuint ; from: -enterItem.width ; to: 0              ; duration: 350 }
            PropertyAnimation { target: exitItem  ; property: "x" ; easing.type: Easing.OutQuint ; from: exitItem.x       ; to: exitItem.width ; duration: 500 }
        }
    }
}
