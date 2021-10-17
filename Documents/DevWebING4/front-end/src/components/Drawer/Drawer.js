import * as React from "react";
import Box from "@mui/material/Box";
import SwipeableDrawer from "@mui/material/SwipeableDrawer";
import List from "@mui/material/List";
import { Typography } from "@mui/material";
import Divider from "@mui/material/Divider";
import ListItem from "@mui/material/ListItem";
import ListItemIcon from "@mui/material/ListItemIcon";
import ListItemText from "@mui/material/ListItemText";
import { Avatar } from "@mui/material";
import AccountCircleIcon from "@mui/icons-material/AccountCircle";
import GroupIcon from "@mui/icons-material/Group";
import GroupsIcon from "@mui/icons-material/Groups";
import SettingsIcon from "@mui/icons-material/Settings";
import LogoutIcon from "@mui/icons-material/Logout";
import stringAvatar from "../Avatar/Avatar";

const Drawer = ({ open, OpenDrawer, user, logOut, switchDark }) => {

  const list = () => (
    <Box
      sx={{ auto: 250 }}
      role="presentation"
      onClick={() => {
        OpenDrawer(true);
      }}
      onKeyDown={() => {
        OpenDrawer(false);
      }}
    >
      <List>
        <ListItem key={"avatar"}>
          <ListItemIcon>
            {user.avatarUrl === "" ? (
              <Avatar {...stringAvatar(user.firstname + " " + user.lastname)} />
            ) : (
              <Avatar src={user.avatarUrl} />
            )}
          </ListItemIcon>
          <Typography variant="h6">
            {user.firstname} {user.lastname}
          </Typography>
        </ListItem>
      </List>
      <Divider />
      <List>
        <ListItem button key={"account"}>
          <ListItemIcon>
            <AccountCircleIcon />
          </ListItemIcon>
          <ListItemText primary={"My account"} />
        </ListItem>
        <ListItem button key={"friends"}>
          <ListItemIcon>
            <GroupIcon />
          </ListItemIcon>
          <ListItemText primary={"My friends"} />
        </ListItem>
        <ListItem button key={"groups"}>
          <ListItemIcon>
            <GroupsIcon />
          </ListItemIcon>
          <ListItemText primary={"My chat groups"} />
        </ListItem>
      </List>
      <Divider />
      <List>
        <ListItem button key={"settings"}>
          <ListItemIcon>
            <SettingsIcon />
          </ListItemIcon>
          <ListItemText primary={"My settings"} />
        </ListItem>
        <Divider />
        <ListItem key={"mode"}>
          <ListItemIcon>{switchDark}</ListItemIcon>
          <ListItemText primary={"Change mode"} />
        </ListItem>
        <Divider />
        <ListItem button key={"logout"} sx={{ color: "red" }} onClick={logOut}>
          <ListItemIcon>
            <LogoutIcon sx={{ color: "red" }} />
          </ListItemIcon>
          <ListItemText primary={"Log out"} />
        </ListItem>
      </List>
    </Box>
  );

  return (
    <div>
      <React.Fragment>
        <SwipeableDrawer
          anchor={"left"}
          open={open}
          onClose={() => {
            OpenDrawer(false);
          }}
          onOpen={() => {
            OpenDrawer(true);
          }}
        >
          {list("left")}
        </SwipeableDrawer>
      </React.Fragment>
    </div>
  );
};
export default Drawer;
