#pragma once
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "raylib.h"

class AnimatedSprite {
public:
    std::string m_current_animation;
    Texture2D m_texture;
    int m_frame_width;
    int m_frame_height;
    std::map<std::string, std::vector<int>> m_animations;
    unsigned int m_current_frame_index;
    float m_frame_time;
    float m_elapsed_time;

    AnimatedSprite(const std::string& tex, int fw, int fh, std::map<std::string, std::vector<int>> anims, float ft)
        : m_texture(LoadTexture(tex.c_str())), m_frame_width(fw), m_frame_height(fh), m_animations(std::move(anims)), m_frame_time(ft), m_elapsed_time(0.0f), m_current_frame_index(0) 
    {
        if (!m_animations.empty()) {
            m_current_animation = m_animations.begin()->first;
        } else {
            std::cerr << "[Warning] No animations provided!" << std::endl;
        }
    }

    void PlayAnimation(const std::string& animation_name);

    void Update(float delta_time);

    void Draw(const Vector2 &pos) const;

    void Unload() {
        UnloadTexture(m_texture);
    }

};