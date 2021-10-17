import React, { useEffect, useState } from "react";
import ListItem from "@mui/material/ListItem";
import ListItemText from "@mui/material/ListItemText";
import ListItemAvatar from "@mui/material/ListItemAvatar";
import Avatar from "@mui/material/Avatar";
import shortString from "../../../../functions/ShortString/ShortString";
import Typography from "@mui/material/Typography";
import stringAvatar from "../../../Avatar/Avatar";
const Conversation = ({responsive, conversation, active, setActiveConversation }) => {
  
  const ActiveConversation = () => (
    <ListItem
      button
      onClick={() => {
        setActiveConversation(conversation);
      }}
      alignItems="flex-start"
      sx={{
        bgcolor: "unReadTextColor.main",
        width: "95%",
        marginTop: "3px",
        marginBottom: "3px",
        margin: "auto",
        borderRadius: "20px",
      }}
    >
      <ListItemAvatar>
        <Avatar
          {...stringAvatar(
            conversation.users[0].firstname +
              " " +
              conversation.users[0].lastname
          )}
          alt="avatar"
        />
      </ListItemAvatar>
      {responsive && (
        <ListItemText
          primary={
            <Typography
              sx={{ display: "inline", fontSize: "16px" }}
              component="span"
              variant="body3"
              color="text.primary"
            >
              {conversation.users[0].firstname +
                " " +
                conversation.users[0].lastname}
              {
                <Typography
                  sx={{
                    display: "inline",
                    fontSize: "10px",
                    marginLeft: "5px",
                  }}
                  component="span"
                  variant="body"
                  color="text.primary"
                >
                  {conversation.messages[0].createdAt}
                </Typography>
              }
            </Typography>
          }
          secondary={
            <React.Fragment>
              {conversation.messages[0].type === "media" ? (
                <Typography variant="body2" style={{ fontStyle: "italic" }}>
                  {conversation.users[0].firstname} sent a media.
                </Typography>
              ) : (
                <Typography
                  dangerouslySetInnerHTML={{
                    __html: shortString(conversation.messages[0].body, 35),
                  }}
                  variant="body2"
                />
              )}
            </React.Fragment>
          }
        />
      )}
    </ListItem>
  );
  const NotActiveConversation = () => (
    <ListItem
      button
      onClick={() => setActiveConversation(conversation)}
      alignItems="flex-start"
      sx={{
        boxShadow: "0 2px 4px 0 rgba(0,0,0,.2)",
        bgcolor: "unReadTextColor.main",
        width: "95%",
        margin: "auto",
        marginTop: "6px",
        marginBottom: "6px",
        borderRadius: "20px",
      }}
    >
      <ListItemAvatar>
        <Avatar
          {...stringAvatar(
            conversation.users[0].firstname +
              " " +
              conversation.users[0].lastname
          )}
          alt="avatar"
          src={""}
        />
      </ListItemAvatar>
      {responsive && (
        <ListItemText
          primary={
            <Typography
              sx={{ display: "inline" }}
              component="span"
              variant="body3"
              color="unReadTextColor.main"
              fontWeight="bold"
            >
              {conversation.users[0].firstname +
                " " +
                conversation.users[0].lastname}
            </Typography>
          }
          secondary={
            <React.Fragment>
              <Typography
                sx={{ display: "inline" }}
                component="span"
                variant="body"
                color="unReadTextColor.main"
              >
                {conversation.messages[0].createdAt}
              </Typography>
              <Typography
                fontWeight="bold"
                variant="body2"
                color="unReadTextColor.main"
                dangerouslySetInnerHTML={{
                  __html: shortString(conversation.messages[0].body, 35),
                }}
              ></Typography>
            </React.Fragment>
          }
        />
      )}
    </ListItem>
  );
  return <>{!active ? <ActiveConversation /> : <NotActiveConversation />}</>;
};

export default Conversation;
