import React from "react";
import { Avatar, Typography } from "@mui/material";
import stringAvatar from "../Avatar/Avatar";
import { Fab } from "@mui/material";
import MouseOverPopover from "../MousePopper/MousePopper";
import AddIcon from "@mui/icons-material/Add";
const GroupChatList = ({ list }) => {
  return (
    <div style = {{overflowX:'hidden', zIndex:23}}>
      <Typography variant="body">Chats({list.length})</Typography>
      <MouseOverPopover content={"Create a group chat"}>
        <Fab sx={{ margin: "3px" }} color="primary" aria-label="add">
          <AddIcon />
        </Fab>
      </MouseOverPopover>
      {list &&
        list.map((item) => (
          <MouseOverPopover content={item.name}>
            <Fab sx={{ margin: "3px" }}>
              <Avatar
                style={{ width: "100%", height: "100%" }}
                src={item?.avatarUrl}
                {...stringAvatar(item.name)}
              ></Avatar>
            </Fab>
          </MouseOverPopover>
        ))}
    </div>
  );
};

export default GroupChatList;
