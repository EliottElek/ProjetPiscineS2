import React, { useState } from "react";
import "./App.css";
import MainContainer from "./components/Container/MainContainer";
import channels from "./dummy";

const styles = {
  root: {
    width: "100%",
    height: "100vh",
    padding: 0,
    margin: 0,
  },
};

const App = () => {
  const [channel, setChannel] = useState(channels[0]);
  const handleChangeChannel = (newChannel) => {
    setChannel(newChannel);
  };
  const [messages, setMessages] = useState([
    {
      author: "Sergei Kudinov",
      creation: "12:13",
      content: "Merci",
    },
  ]);
  const addMessage = (message) => {
    setMessages([...messages, message]);
  };
  return (
    <div style={styles.root}>
      <MainContainer
        messages={messages}
        channels={channels}
        channel={channel}
        addMessage={addMessage}
      />
    </div>
  );
};

export default App;
