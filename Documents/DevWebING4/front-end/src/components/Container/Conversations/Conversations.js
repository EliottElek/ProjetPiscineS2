import * as React from "react";
import List from "@mui/material/List";
import Conversation from "./Conversation/Conversation";
import { Typography } from "@mui/material";
const Conversations = ({responsive, conversations, setActive, setActiveConversation }) => {
  return (
    <React.Fragment>
      <List className="list" sx={{ width: "100%" }}>
        {conversations.length === 0 ? (
          <div
            style={{
              display: "flex",
              flexDirection: "column",
              justifyContent: "center",
              alignItems: "center",
            }}
          >
            <Typography align="center">
              You don't have any conversation yet.
            </Typography>
          </div>
        ) : (
          conversations.map((conversation) => (
            <>
              <Conversation responsive = {responsive}
                setActiveConversation={setActiveConversation}
                conversation={conversation}
              />
            </>
          ))
        )}
      </List>
    </React.Fragment>
  );
};
export default Conversations;
