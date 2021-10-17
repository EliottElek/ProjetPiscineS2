import React, { useState } from "react";
import user from "../../dummy/user";
import { Avatar, Button } from "@mui/material";
import SendIcon from "@mui/icons-material/Send";
import stringAvatar from "../Avatar/Avatar";
import MouseOverPopover from "../MousePopper/MousePopper";
import AddCircleOutlineIcon from "@mui/icons-material/AddCircleOutline";
import SentimentVeryDissatisfiedIcon from "@mui/icons-material/SentimentVeryDissatisfied";
import AppBar from "../AppBar/AppBar";
import {
  Paper,
  Typography,
  TextField,
  IconButton,
  CircularProgress,
} from "@mui/material";
import { Divider } from "@material-ui/core";
const Chat = ({ conversation }) => {
  const [scrollYDire, setScrollY] = useState(0);
  const [message, setMessage] = useState("");
  const [scrolled, setScrolled] = useState(false);
  const handleChange = (event) => {
    setMessage(event.target.value);
  };
  const handleSendMessage = (e) => {
    e.preventDefault();
    setMessage("");
  };
  const scroller = document.getElementById("scroller");
  const handleScroll = (e) => {
    scroller.onscroll = function (event) {
      console.log(scroller.scrollY);
    };
    if (scrollYDire < e.target.scrollY) {
      setScrolled(true);
      console.log("going up");
    } else if (scrollYDire > e.target.scrollY) {
      setScrolled(false);
      console.log("going down");
    }
    setScrollY(e.target.scrollY);
    console.log(e.target.scrollY);
  };
  return (
    <div
      id="scroller"
      style={{
        height: "100vh",
        display: "grid",
        gridTemplateRows: "89% 60px",
        gridGap: "1%",
      }}
    >
      <div
        id="scroller"
        onScroll={handleScroll}
        style={{
          overflowY: "scroll",
          height: "100%",
          padding: "3px",
          margin: "3px",
          paddingBottom: "23px",
          paddingTop: "60px",
        }}
      >
        <AppBar scrolled={scrolled} conversation={conversation} />
        {conversation === undefined ? (
          <div
            style={{
              height: "100%",
              width: "100%",
              display: "flex",
              flexDirection: "column",
              justifyContent: "center",
              alignItems: "center",
            }}
          >
            <>
              <Typography variant="h5">No message yet</Typography>
              <SentimentVeryDissatisfiedIcon size="large" />
              <Divider />
              <Typography variant="body">No friend ? Find one !</Typography>
              <Button
                sx={{ bgcolor: "gray", color: "white", margin: "10px" }}
                variant="contained"
              >
                <AddCircleOutlineIcon sx={{ marginRight: "8px" }} /> Add a
                friend
              </Button>
            </>
          </div>
        ) : (
          conversation?.messages
            ?.map((message) => (
              <>
                {user.id !== message.userId ? (
                  <div
                    style={{
                      display: "flex",
                      flexDirection: "column",
                      justifyContent: "center",
                      alignItems: "flex-start",
                      width: "100%",
                      padding: message.type === "media" ? "0px" : "10px",
                    }}
                  >
                    <div
                      style={{
                        display: "flex",
                        flexDirection: "row",
                        width: "100%",
                      }}
                    >
                      <MouseOverPopover content={"You :)"}>
                        <Avatar
                          style={{ margin: "5px" }}
                          src={user.avatarUrl}
                        ></Avatar>
                      </MouseOverPopover>
                      <Paper
                        style={{
                          display: "flex",
                          flexDirection: "column",
                          justifyContent: "center",
                          alignItems: "flex-start",
                          maxWidth: "70%",
                          minHeight: "50px",
                          borderRadius: "10px",
                          padding: message.type === "media" ? "0px" : "10px",
                        }}
                        elevation={3}
                      >
                        {message.body ? (
                          <div
                            dangerouslySetInnerHTML={{ __html: message?.body }}
                            sx={{ fontSize: "15px" }}
                          ></div>
                        ) : (
                          <div>
                            <CircularProgress />
                          </div>
                        )}
                      </Paper>
                    </div>
                    <Typography sx={{ fontSize: "10px" }}>
                      {message?.createdAt}
                    </Typography>
                  </div>
                ) : (
                  <div
                    style={{
                      display: "flex",
                      flexDirection: "column",
                      justifyContent: "center",
                      alignItems: "flex-end",
                      width: "100%",
                      padding: message.type === "media" ? "0px" : "10px",
                    }}
                  >
                    <div
                      style={{
                        display: "flex",
                        flexDirection: "row",
                        width: "100%",
                        justifyContent: "right",
                      }}
                    >
                      <Paper
                        style={{
                          display: "flex",
                          maxWidth: "70%",
                          flexDirection: "column",
                          justifyContent: "center",
                          alignItems: "flex-start",
                          minHeight: "50px",
                          borderRadius: "10px",
                          padding: message.type === "media" ? "0px" : "10px",
                        }}
                        elevation={3}
                      >
                        {message.body ? (
                          <div
                            dangerouslySetInnerHTML={{ __html: message?.body }}
                            sx={{ fontSize: "15px" }}
                          ></div>
                        ) : (
                          <div>
                            <CircularProgress />
                          </div>
                        )}
                      </Paper>
                      <MouseOverPopover
                        content={
                          conversation.users[0].firstname +
                          " " +
                          conversation.users[0].lastname
                        }
                      >
                        <Avatar
                          style={{ margin: "5px" }}
                          {...stringAvatar(
                            conversation.users[0].firstname +
                              " " +
                              conversation.users[0].lastname
                          )}
                        ></Avatar>
                      </MouseOverPopover>
                    </div>
                    <Typography sx={{ fontSize: "10px" }}>
                      {message?.createdAt}
                    </Typography>
                  </div>
                )}
              </>
            ))
            .reverse()
        )}
      </div>
      <form
        style={{
          display: "flex",
          flexDirection: "row",
          justifyContent: "center",
          alignItems: "center",
          padding: 0,
          margin: 0,
        }}
        onSubmit={handleSendMessage}
      >
        <div
          style={{
            display: "flex",
            flexDirection: "row",
            justifyContent: "center",
            alignItems: "center",
            height: "100%",
            width: "100%",
            padding: 0,
            margin: 0,
            borderTop: "solid 0.5px grey",
          }}
        >
          <TextField
            disabled={conversation === undefined ? true : false}
            autoComplete="off"
            type="text"
            fullWidth
            id="fullWidth"
            placeholder="Type your message here..."
            value={message}
            onChange={handleChange}
          />
          <IconButton disabled={message === "" ? true : false}>
            <SendIcon
              onClick={handleSendMessage}
              type="submit"
              fontSize="large"
            ></SendIcon>
          </IconButton>
        </div>
      </form>
    </div>
  );
};
export default Chat;
