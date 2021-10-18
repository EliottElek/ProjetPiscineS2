import React, { useState } from "react";
import ListItem from "@mui/material/ListItem";
import ListItemText from "@mui/material/ListItemText";
import ListItemAvatar from "@mui/material/ListItemAvatar";
import Avatar from "@mui/material/Avatar";
import ListItemButton from "@mui/material/ListItemButton";
import Typography from "@mui/material/Typography";
import "./style.css";
const styles = {
  root: {
    background: "transparent",
    width: "95%",
    padding: 0,
    margin: "1px auto 1px auto",
    borderRadius: "8px",
  },
  rootActive: {
    background: "#424242",
    width: "95%",
    padding: 0,
    margin: "1px auto 1px auto",
    borderRadius: "8px",
  },
  text: {
    color: "#8e9297",
  },
  item: {
    padding: 3,
  },
  avatar: { marginLeft: 3, width: 30, height: 30 },
};
const ChannelItem = ({ channel }) => {
  const [active, setActive] = useState(false);
  return (
    <ListItemButton className="hover" style={styles.root}>
      <ListItem style={styles.item}>
        <ListItemAvatar>
          <Avatar style={styles.avatar}>#</Avatar>
        </ListItemAvatar>
        <ListItemText style={styles.text}>
          <Typography variant="body1">{channel.name}</Typography>
        </ListItemText>
      </ListItem>
    </ListItemButton>
  );
};

export default ChannelItem;
