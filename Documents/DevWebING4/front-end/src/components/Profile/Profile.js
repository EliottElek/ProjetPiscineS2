import * as React from "react";
import ListItem from "@mui/material/ListItem";
import ListItemIcon from "@mui/material/ListItemIcon";
import Box from "@mui/material/Box";
import { Avatar } from "@mui/material";
import IconButton from "@mui/material/IconButton";
import Drawer from "../Drawer/Drawer";
import MoreVertIcon from "@mui/icons-material/MoreVert";
import { Typography } from "@mui/material";
import stringAvatar from "../Avatar/Avatar";
export default function Profile({ responsive, user, logOut, switchDark }) {
  const [open, setOpen] = React.useState(false);
  const OpenDrawer = (bool) => {
    setOpen(bool);
  };

  return (
    <>
      <Box
        sx={{
          flexGrow: 1,
          height: "100%",
          bgcolor: "primary.main",
          borderRadius: "20px",
        }}
      >
        <ListItem key={"avatar"}>
          <ListItemIcon>
            {user.avatarUrl === "" ? (
              <Avatar
                {...stringAvatar(user.firstname + " " + user.lastname, 56, 56)}
              />
            ) : (
              <Avatar
                sx={{ width: 56, height: 56, margin: "10px" }}
                src={user.avatarUrl}
              />
            )}
          </ListItemIcon>
          {responsive && (
            <Typography variant="h5" color="text.primary">
              {user.firstname} {user.lastname}
            </Typography>
          )}
          <Box sx={{ flexGrow: 1 }} />
          <Box sx={{ display: { xs: "block", md: "flex" } }}>
            <IconButton
              size="large"
              edge="end"
              aria-label="account of current user"
              aria-haspopup="true"
              onClick={OpenDrawer}
            >
              <MoreVertIcon size="large" />
            </IconButton>
          </Box>
        </ListItem>
      </Box>
      <Drawer
        logOut={logOut}
        open={open}
        OpenDrawer={OpenDrawer}
        user={user}
        switchDark={switchDark}
      />
    </>
  );
}
