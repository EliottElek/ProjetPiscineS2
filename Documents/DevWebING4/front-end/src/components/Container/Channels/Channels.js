import React from "react";
import {
  List,
  Divider,
  ListItem,
  ListItemText,
  IconButton,
} from "@mui/material";
import ChannelItem from "./ChannelItem/ChannelItem";
import AddIcon from "@mui/icons-material/Add";
const styles = {
  root: {
    width: "100%",
    height: "100%",
    backgroundColor: "#2f3136",
  },
  list: { width: "100%", height: "100%", bgcolor: "#2f3136", color: "#D9E2EC" },
  channels: {
    display: "flex",
    justifyContent: "space-between",
    alignItems: "center",
    color: "#8e9297",
  },
  add: {
    color: "#8e9297",
    width: "20px",
  },
};
const Channels = ({ channels, message }) => {
  return (
    <div style={styles.root}>
      <List sx={styles.list}>
        <ListItem sx={styles.channels}>
          <ListItemText>Channels</ListItemText>
          <IconButton>
            <AddIcon style={styles.add} />
          </IconButton>
        </ListItem>
        <Divider />
        {channels?.map((channel) => (
          <ChannelItem channel={channel} message={message} />
        ))}
      </List>
    </div>
  );
};

export default Channels;
