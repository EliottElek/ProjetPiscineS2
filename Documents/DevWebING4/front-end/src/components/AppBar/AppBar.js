import * as React from "react";
import { Slide, Box } from "@material-ui/core";
import AppBar from "@mui/material/AppBar";
import Toolbar from "@mui/material/Toolbar";
import Typography from "@mui/material/Typography";
import { IconButton } from "@material-ui/core";
import MoreVertIcon from "@mui/icons-material/MoreVert";
import { Avatar } from "@material-ui/core";
import stringAvatar from "../Avatar/Avatar";

export default function HideAppBar({ scrolled, conversation }) {

  return (
    <Box>
      <Slide
        direction="down"
        in={!scrolled}
        mountOnEnter
        unmountOnExit
      >
        <AppBar
          sx={{
            position: "fixed",
            right: 0,
            zIndex: 1,
          }}
        >
          <Toolbar sx={{ bgcolor: "primary.main" }}>
            <Box sx={{ flexGrow: 1 }} />
            {conversation && (
              <>
                {conversation?.users[0]?.avatarUrl === "" ? (
                  <Box>
                    <Avatar
                      sx={{ width: 56, height: 56, margin: "10px" }}
                      {...stringAvatar(
                        conversation?.users[0]?.firstname +
                          " " +
                          conversation?.users[0]?.lastname,
                        56,
                        56
                      )}
                    />
                  </Box>
                ) : (
                  <Box>
                    <Avatar
                      sx={{ width: 56, height: 56, margin: "10px" }}
                      src={conversation?.users[0]?.avatarUrl}
                    />
                  </Box>
                )}
                <Typography variant="h6" component="div">
                  {conversation?.users[0]?.firstname +
                    " " +
                    conversation?.users[0]?.lastname}
                </Typography>
                <Box sx={{ display: { xs: "block", md: "flex" } }}>
                  <IconButton
                    size="large"
                    edge="end"
                    aria-label="account of current discusser"
                    aria-haspopup="true"
                  >
                    <MoreVertIcon size="large" />
                  </IconButton>
                </Box>
              </>
            )}
          </Toolbar>
        </AppBar>
      </Slide>
    </Box>
  );
}
