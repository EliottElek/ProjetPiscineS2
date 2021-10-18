import React from "react";
import AlternateEmailIcon from "@mui/icons-material/AlternateEmail";
import PersonAddIcon from "@mui/icons-material/PersonAdd";
import HelpOutlineIcon from "@mui/icons-material/HelpOutline";
import MoreHorizIcon from "@mui/icons-material/MoreHoriz";
import { Typography, IconButton } from "@mui/material";
import SearchBar from "../../Channels/SearchBar/SearchBar";
const styles = {
  appbar: {
    width: "100%",
    height: "100%",
    display: "flex",
    justifyContent: "space-between",
    alignItems: "center",
    padding: "0px 15px 0px 15px",
  },
  at: {
    color: "#8e9297",
    display: "flex",
    justifyContent: "space-between",
    alignItems: "center",
  },
  icon: {
    color: "#8e9297",
  },
};
const AppBar = ({ channel }) => {
  return (
    <div style={styles.appbar}>
      <div style={styles.at}>
        <AlternateEmailIcon />
        <Typography variant="h6">{channel.name}</Typography>
      </div>
      <div style={styles.at}>
        <IconButton>
          <PersonAddIcon style={styles.icon} />
        </IconButton>
        <SearchBar place ={"Search in conversation..."}/>
        <IconButton>
          <HelpOutlineIcon style={styles.icon} />
        </IconButton>
        <IconButton>
          <MoreHorizIcon style={styles.icon} />
        </IconButton>
      </div>
    </div>
  );
};

export default AppBar;
