import * as React from "react";
import "./style.css";
import { Card } from "@mui/material";
import Chat from "../Chat/Chat";
import { Grid } from "@mui/material";
import Conversations from "./Conversations/Conversations";
import GroupChatList from "../GroupChatList/GroupChatList";
import Profile from "../Profile/Profile";

const Container = ({ user, logOut, switchDark }) => {
  const [responsive, setResponsive] = React.useState(false);
  React.useEffect(() => {
    const fetchData = async () => {
      try {
        const data = await fetch("https://localhost:5000/users");
        console.log(data);
      } catch (err) {
        console.error();
      }
    };
    fetchData();
    const setResponsiveness = () => {
      return window.innerWidth < 900
        ? setResponsive(false)
        : setResponsive(true);
    };

    setResponsiveness();
    window.addEventListener("resize", () => setResponsiveness());

    return () => {
      window.removeEventListener("resize", () => setResponsiveness());
    };
  }, []);
  const setActiveConversation = (conversation) => {
    setConversation(conversation);
  };
  const [activeConversation, setConversation] = React.useState(
    user.conversations ? user?.conversations[0] : null
  );
  console.log(activeConversation);
  const LeftPart = ({ user, children }) => {
    return (
      <div
        className="conversationContainer"
        style={{
          zIndex: 13,
          maxHeight: "100%",
          borderRight: "0.25px solid grey",
        }}
      >
        <Card
          elevation={0}
          sx={{
            bgcolor: "primary.main",
            borderRadius: "0px",
          }}
        >
          {children}
        </Card>
        <Card
          elevation={0}
          className="conversationContainerConvosContainer"
          sx={{
            bgcolor: "primary.main",
            borderRadius: "0px",
            borderTop: "0.5px solid grey",
          }}
        >
          <div className="conversationContainerGroupChats">
            <div className="conversationGroupChats">
              <GroupChatList list={user.chatList} />
            </div>
          </div>
          <div className="conversationContainerConvos">
            <Conversations
              responsive={responsive}
              setActiveConversation={setActiveConversation}
              conversations={user.conversations}
            />
          </div>
        </Card>
      </div>
    );
  };
  return (
    <Grid container sx={{ maxHeight: "100%" }}>
      <Grid item xs={4} md={4} style={{ zIndex: 15 }}>
        <LeftPart
          user={user}
          children={
            <Profile
              responsive={responsive}
              logOut={logOut}
              user={user}
              switchDark={switchDark}
            ></Profile>
          }
        />
      </Grid>
      <Grid item xs={8} md={8}>
        <Card
          sx={{
            bgcolor: "primary.main",
            width: "100%",
            height: "100%",
            overflowY: "scroll",
            borderRadius: "0px",
            boxShadow: "inset 0 2px 4px 0 rgba(0,0,0,.9)",
          }}
          elevation={0}
        >
          <Chat conversation={activeConversation} />
        </Card>
      </Grid>
    </Grid>
  );
};
export default Container;
