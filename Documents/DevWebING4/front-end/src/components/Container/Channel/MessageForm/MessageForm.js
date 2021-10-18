import React, { useState } from "react";
import { IconButton } from "@mui/material";
import AttachFileIcon from "@mui/icons-material/AttachFile";
import SendIcon from "@mui/icons-material/Send";
import getCurrentTime from "../../../../functions/time";
const styles = {
  input: {
    height: "35px",
    borderRadius: "10px",
    width: "100%",
    border: "none",
    outline: "none",
    background: "#424242",
    color: "#D9E2EC",
    paddingLeft: "10px",
    marginTop:'3px'
  },
  icon: {
    color: "#D9E2EC",
  },
};
function gotoBottom(id) {
  var element = document.getElementById(id);
  element.scrollTop = element.scrollHeight - element.clientHeight;
  element.scrollTo({
    top: element.scrollHeight,
    left: 0,
    behavior: "smooth",
  });
}

const MessageForm = ({ addMessage }) => {
  const [message, setMessage] = useState("");
  const handleChange = (e) => {
    setMessage(e.target.value);
  };
  const onSubmit = (e) => {
    if (message !== "") {
      var time = getCurrentTime();
      e.preventDefault();
      addMessage({
        content: message,
        author: "david Worms",
        creation: time,
      });
      setMessage("");
      gotoBottom("middleContainer");
    }
  };
  return (
    <form
      onSubmit={onSubmit}
      style={{ width: "100%", display: "flex", alignItems: "center" }}
    >
      <IconButton>
        <AttachFileIcon sx={styles.icon} />
      </IconButton>
      <input
        placeholder="Type your message here..."
        autoComplete="off"
        type="input"
        name="content"
        style={styles.input}
        value={message}
        onChange={handleChange}
      />
      <IconButton disabled={message === "" ? true : false}>
        <SendIcon style={styles.icon} type="submit"></SendIcon>
      </IconButton>
    </form>
  );
};
export default MessageForm;
