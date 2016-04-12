# QChatDemo
Demo of a chat app with a list of contacts and related messages.

The app has two type of view: on small screen, it use a stacked view, otherwise the contact list and the message list are side by side. This behaviour simulate smarphone and tablet devices.

The chat messages are lazy loaded, to load previous conversations swipe down the message list.

Since this is a demo app, the following simplifications were made:
- db is filled with mocked data, this cause a startup delay at first run;
- for the contacts list, the index is used as id, instead a unique id should be used;
- for the messages, should be used an id as primary key instead of the set (userId, senderId, timestamp)
- contact selection is not saved, so if you switch type of view (side/stacked view) it is not persisted.
