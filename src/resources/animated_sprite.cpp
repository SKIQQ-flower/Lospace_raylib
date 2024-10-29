#include "./animated_sprite.hpp"

void AnimatedSprite::PlayAnimation(const std::string& animation_name) {
    if (m_animations.find(animation_name) != m_animations.end()) {
        m_current_animation = animation_name;
        m_current_frame_index = 0;
        m_elapsed_time = 0.0f;
    } else {
        std::cerr << "Animation not found: " << animation_name << std::endl;
    }
}

void AnimatedSprite::Update(float delta_time) {
    m_elapsed_time += delta_time;

    if (m_elapsed_time >= m_frame_time) {
        m_elapsed_time = 0.0f;

        auto& animation = m_animations[m_current_animation];
        m_current_frame_index = (m_current_frame_index + 1) % animation.size();
    }
}

void AnimatedSprite::Draw(const Vector2& pos) const {
    auto& animation = m_animations.at(m_current_animation);
    int frame = animation[m_current_frame_index];

    Rectangle rect{
        static_cast<float>(frame * m_frame_width), 0.0f,
        static_cast<float>(m_frame_width), static_cast<float>(m_frame_height)
    };

    DrawTexturePro(m_texture, rect, 
        Rectangle{pos.x, pos.y, static_cast<float>(m_frame_width),static_cast<float>(m_frame_height)}, 
        Vector2{m_frame_width / 2.0f, m_frame_height / 2.0f}, 0.0f, WHITE);
}
