import React from "react";
import ListItemText from "@mui/material/ListItemText";
import ListItemAvatar from "@mui/material/ListItemAvatar";
import { ListItem, Typography, Avatar, Paper } from "@mui/material";
import ReactMarkdown from "react-markdown";

const styles = {
  message: {
    padding: "0px 12px 0px 12px",
    background: "#424242",
    opacity: "0.9",
  },
  title: {
    color: "#6588DE",
  },
  content: {
    color: "#D9E2EC",
    fontWeight:'200'
  },
  item: {
    background: "transparent",
  },
  time: {
    color: "gray",
    fontSize: "0.5em",
  },
};

const Message = ({ message }) => {
  return (
    <ListItem sx={styles.item}>
      <ListItemAvatar>
        <Avatar></Avatar>
      </ListItemAvatar>
      <Paper elevation={0} sx={styles.message}>
        <ListItemText
          style={{ height: "auto" }}
          primary={
            <Typography variant="body3" style={styles.title}>
              {message.author}
            </Typography>
          }
          secondary={
            <div
              style={{
                display: "flex",
                alignItems: "center",
              }}
            >
              <Typography variant = 'body1' style={styles.content}>
                <ReactMarkdown>
                  {message.content}
                </ReactMarkdown>
              </Typography>
            </div>
          }
        />
      </Paper>
      <Typography style={styles.time} variant="caption">
        {message.creation}
      </Typography>
    </ListItem>
  );
};

export default Message;
