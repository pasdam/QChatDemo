import QtQuick 2.5

Row {
    spacing: 10

    signal loadMore()
    signal selectContact(int index)

    ContactList {
        id             : contactList
        
        width          : 200
        height         : parent.height
        
        onSelectContact: root.selectContact(index)
    }

    MessageList {
        width     : parent.width - contactList.width - parent.spacing*2
        height    : parent.height
        
        onLoadMore: root.loadMore()
    }
}
